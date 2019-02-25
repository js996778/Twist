#ifndef TWIST_FILTER_HPP
#define TWIST_FILTER_HPP

#define IMGUI_DEFINE_MATH_OPERATORS
#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"

#include "twen/nodes/FilterNode.hpp"

static void Filter_gui(Node* node) {
	FilterNode *n = dynamic_cast<FilterNode*>(node);

	static const char* FILTERS[] = {
		"Low-Pass", "High-Pass",
		"Band-Pass", "All-Pass",
		"Notch", "Peaking",
		"Low-Shelf", "High-Shelf"
	};

	ImGui::PushItemWidth(80);
	ImGui::Combo("Filter", (int*)&n->filter, FILTERS, 8);

	switch (n->filter) {
		case FilterNode::LowPass:
		case FilterNode::HighPass: {
			if (n->connected(1)) {
				ImGui::Text("CutOff: %.2f", n->in(1).value());
			} else {
				ImGui::DragFloat("CutOff", &n->params[0], 1.0f, 20.0f, 16000.0f);
			}
			if (n->connected(2)) {
				ImGui::Text("Resonance: %.2f", n->in(2).value());
			} else {
				ImGui::DragFloat("Resonance", &n->params[1], 0.1f, -100.0f, 100.0f);
			}
		} break;
		case FilterNode::BandPass:
		case FilterNode::AllPass:
		case FilterNode::Notch: {
			if (n->connected(1)) {
				ImGui::Text("Frequency: %.2f", n->in(1).value());
			} else {
				ImGui::DragFloat("Frequency", &n->params[0], 1.0f, 20.0f, 16000.0f);
			}
			if (n->connected(2)) {
				ImGui::Text("Q: %.2f", n->in(2).value());
			} else {
				ImGui::DragFloat("Q", &n->params[1], 0.01f, 0.0f, 1.0f);
			}
		} break;
		case FilterNode::Peaking:
		case FilterNode::LowShelf:
		case FilterNode::HighShelf: {
			if (n->connected(1)) {
				ImGui::Text("Frequency: %.2f", n->in(1).value());
			} else {
				ImGui::DragFloat("Frequency", &n->params[0], 1.0f, 20.0f, 16000.0f);
			}
			if (n->connected(2)) {
				ImGui::Text("Q: %.2f", n->in(2).value());
			} else {
				ImGui::DragFloat("Q", &n->params[1], 0.01f, 0.0f, 1.0f);
			}
			if (n->connected(3)) {
				ImGui::Text("Gain: %.2f", n->in(3).value());
			} else {
				ImGui::DragFloat("Gain", &n->params[2], 0.01f, 0.0f, 1.0f);
			}
		} break;
	}
	ImGui::PopItemWidth();
}

#endif // TWIST_FILTER_HPP
