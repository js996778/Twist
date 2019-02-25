#ifndef TWEN_FILTER_NODE_H
#define TWEN_FILTER_NODE_H

#include "../NodeGraph.h"

extern "C" {
	#include "biquad.h"
}

class FilterNode : public Node {
	TWEN_NODE(FilterNode, "Filter")
public:
	enum Filter {
		LowPass = 0,
		HighPass,
		BandPass,
		AllPass,
		Notch,
		Peaking,
		LowShelf,
		HighShelf
	};

	FilterNode(float a=20, float b=0.0f, float c=0.0f, Filter filter=Filter::LowPass)
		: Node(), filter(filter)
	{
		addInput("In"); // Input
		addInput("Freq"); // Cutoff/Frequency
		addInput("Q/Res"); // Resonance/Q
		addInput("Gain"); // Gain

		params[0] = a;
		params[1] = b;
		params[2] = c;
	}

	Value sample(NodeGraph *graph) override {
		float freq  = connected(1) ? in(1).value() : params[0];
		float resoq = connected(2) ? in(2).value() : params[1];
		float gainv = connected(3) ? in(3).value() : params[2];

		float frequency = std::min(std::max(freq, 20.0f), 16000.0f);
		float resonQ = std::min(std::max(resoq, -100.0f), 100.0f);
		float gain = std::min(std::max(gainv, 0.0f), 1.0f);

		float _in = in(0).value();

		int sr = int(graph->sampleRate());
		switch (filter) {
			case LowPass: sf_lowpass(&m_state, sr, frequency, resonQ); break;
			case HighPass: sf_highpass(&m_state, sr, frequency, resonQ); break;
			case BandPass: sf_bandpass(&m_state, sr, frequency, resonQ); break;
			case AllPass: sf_allpass(&m_state, sr, frequency, resonQ); break;
			case Notch: sf_notch(&m_state, sr, frequency, resonQ); break;
			case Peaking: sf_peaking(&m_state, sr, frequency, resonQ, gain); break;
			case LowShelf: sf_lowshelf(&m_state, sr, frequency, resonQ, gain); break;
			case HighShelf: sf_highshelf(&m_state, sr, frequency, resonQ, gain); break;
		}

		sf_sample_st in, out;
		in.L = in.R = _in;
		sf_biquad_process(&m_state, 1, &in, &out);

		return Value((out.L + out.R) * 0.5f);
	}

	void save(JSON& json) override {
		Node::save(json);
		json["params"] = params;
		json["filter"] = int(filter);
	}

	void load(JSON json) override {
		Node::load(json);
		params[0] = json["params"][0];
		params[1] = json["params"][1];
		params[2] = json["params"][2];
		filter = Filter(json["filter"].get<int>());
	}

	Filter filter;
	float params[3];

private:
	sf_biquad_state_st m_state;
};

#endif // TWEN_FILTER_NODE_H
