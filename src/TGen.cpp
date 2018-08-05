#include "TGen.h"

#include <cmath>

constexpr float PI2 = M_PI * 2.0f;

float TOsc::sample() {
	return sample(m_frequency) * 0.5f + 0.5f;
}

float TOsc::sample(float freq) {
	float p = m_phase;

	float v = 0.0f;
	switch (m_waveform) {
		case TOsc::Sine: v = std::sin(p); break;
		case TOsc::Pulse: v = p < M_PI*0.25f ? 1.0f : -1.0f; break;
		case TOsc::Square: v = p < M_PI ? 1.0f : -1.0f; break;
		case TOsc::Saw: v = 1.0f - (1.0f / M_PI * p); break;
		case TOsc::Triangle: {
			if (p < M_PI) {
				v = -1.0f + (2.0f / M_PI) * p;
			} else {
				v = 3.0f - (2.0f / M_PI) * p;
			}
		} break;
		case TOsc::Noise: v = (float(rand()) / RAND_MAX) * 2.0f - 1.0f; break;
	}

	// Modulate
	float Mfreq = freq;
	float Mamp = m_amplitude;

	m_phase += (PI2 * Mfreq) / m_sampleRate;
	if (m_phase > PI2) {
		m_phase -= PI2;
	}

	return v * Mamp;
}

/// ADSR
float TADSR::sample() {
	switch (m_state) {
		case Idle: break;
		case Attack: {
			m_out = m_attackBase + m_out * m_attackCoef;
			if (m_out >= 1.0f) {
				m_out = 1.0f;
				m_state = Decay;
			}
		} break;
		case Decay: {
			m_out = m_decayBase + m_out * m_decayCoef;
			if (m_out <= m_sustain) {
				m_out = m_sustain;
				m_state = Sustain;
			}
		} break;
		case Sustain: break;
		case Release: {
			m_out = m_releaseBase + m_out * m_releaseCoef;
			if (m_out <= 0.0f) {
				m_out = 0.0f;
				m_state = Idle;
			}
		} break;
	}
	m_out = std::max(std::min(m_out, 1.0f), 0.0f);
	return m_out;
}

void TADSR::gate(bool g) {
	if (g) {
		m_state = Attack;
	} else if (m_state != Idle) {
		m_state = Release;
	}
}

float TADSR::coef(float rate, float targetRatio) {
	return (rate <= 0) ? 0.0 : exp(-log((1.0 + targetRatio) / targetRatio) / rate);
}

TWaveGuide::TWaveGuide() {
	clear();
}

void TWaveGuide::clear() {
	m_counter = 0;
	for (int i = 0; i < T_WAVE_GUIDE_SAMPLES; i++) m_buffer[i] = 0;
}

float TWaveGuide::sample(float in, float feedBack, double delay) {
	// calculate delay offset
	double back = m_counter - delay;
	
	// clip lookback buffer-bound
	if (back < 0.0) {
		back = T_WAVE_GUIDE_SAMPLES + back;
	}
	
	// compute interpolation left-floor
	const int index0 = back;
	
	// compute interpolation right-floor
	int index_1 = index0 - 1;
	int index1 = index0 + 1;
	int index2=  index0 + 2;
	
	// clip interp. buffer-bound
	if (index_1 < 0)index_1 = T_WAVE_GUIDE_SAMPLES - 1;
	if (index1 >= T_WAVE_GUIDE_SAMPLES) index1 = 0;
	if (index2 >= T_WAVE_GUIDE_SAMPLES) index2 = 0;
	
	// get neighbourgh samples
	const float y_1 = m_buffer[index_1];
	const float y0 = m_buffer[index0];
	const float y1 = m_buffer[index1];
	const float y2 = m_buffer[index2];
	
	// compute interpolation x
	const float x = float(back) - float(index0);
	
	// calculate
	const float c0 = y0;
	const float c1 = 0.5f * (y1 - y_1);
	const float c2 = y_1 - 2.5f * y0 + 2.0f * y1 - 0.5f * y2;
	const float c3 = 0.5f * (y2 - y_1) + 1.5f * (y0 - y1);
	
	const float output = ((c3 * x + c2) * x + c1) * x + c0;
	
	// add to delay buffer
	m_buffer[m_counter++] = in + output * feedBack;
	
	// clip delay counter
	if (m_counter >= T_WAVE_GUIDE_SAMPLES) m_counter = 0;
	
	// return output
	return output;
}