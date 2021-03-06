#ifndef TWEN_OUT_NODE_H
#define TWEN_OUT_NODE_H

#include "../NodeGraph.h"

class OutNode : public Node {
	TWEN_NODE(OutNode, "Output")
public:
	OutNode() : Node() {
		addInput("In");
		m_signalDC = 0.0f;
		m_envelope = 100.0f;
	}

	Value sample(NodeGraph *graph) override {
		// Compressor
		// from https://github.com/manpat/voi-synth/blob/master/src/context.rs#L182
		// (thanks manpat!)
		const float ATTACK_TIME = 5.0f / 1000.0f;
		const float RELEASE_TIME = 200.0f / 1000.0f;

		float attack =  1.0f - std::exp((-1.0f / (ATTACK_TIME * graph->sampleRate())));
		float release = 1.0f - std::exp((-1.0f / (RELEASE_TIME * graph->sampleRate())));

		float input = in(0).value() * gain;

		m_signalDC = Utils::lerp(m_signalDC, input, 0.5f / graph->sampleRate());
		input -= m_signalDC;

		float inputAbs = std::abs(input);
		if (inputAbs > m_envelope) {
			m_envelope = Utils::lerp(m_envelope, inputAbs, attack);
		} else {
			m_envelope = Utils::lerp(m_envelope, inputAbs, release);
		}
		m_envelope = std::max(m_envelope, 1.0f);

		return Value(std::min(std::max(input * 0.6f / (m_envelope + 0.0001f), -1.0f), 1.0f));
	}

	void save(JSON& json) override {
		Node::save(json);
		json["gain"] = gain;
	}

	void load(JSON json) override {
		Node::load(json);
		gain = json["gain"];
	}

	float gain = 1.0f;

private:
	float m_signalDC, m_envelope;
};

#endif // TWEN_OUT_NODE_H
