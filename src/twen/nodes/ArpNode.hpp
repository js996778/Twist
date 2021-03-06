#ifndef TWEN_ARP_NODE_H
#define TWEN_ARP_NODE_H

#include <iostream>
#include "../NodeGraph.h"

class ArpNode : public Node {
	TWEN_NODE(ArpNode, "Arp")
public:
	enum Chord {
		Major = 0,
		Minor,
		Sus2,
		Sus4,
		Major7,
		Minor7,
		Nineth,
		Octave,
		Sharp5,
		Dim,
		Sixth,
		ChordTypeCount
	};

	enum Direction {
		Up = 0,
		Down,
		UpDown,
		Random,
		DirectionCount
	};

	ArpNode(Note note, Chord chord, Direction dir, u32 oct)
		: Node(), note(note), chord(chord), direction(dir), oct(oct)
	{}

	int index(float ntime, int n) {
		int rn = (int(Utils::lerp(0, n, ntime)) % n);
		if (prevRN != rn) {
			gate = false;
			prevRN = rn;
		} else {
			gate = true;
		}

		switch (direction) {
			case Up: return rn;
			case Down: return n - 1 - rn;
			case UpDown: {
				float cy = Utils::cyclef(ntime * 2.0f);
				float nm = Utils::remap(cy * (n * 2), 0, n*2, 0, n);
				return int(nm);
			};
			case Random: {
				if (prevN != rn) {
					randN = rand() % n;
					prevN = rn;
				}
				return randN;
			};
			default: return rn;
		}
	}

	Value sample(NodeGraph *graph) override {
		float ntime = graph->time();

		int noteIn = note;

#define INDEX(n) index(ntime, n)
		int nt = 0;
		switch (chord) {
			case Major: {
				const int n[] = { 0, 4, 7 };
				nt = n[INDEX(3)] + int(noteIn);
			} break;
			case Minor: {
				const int n[] = { 0, 3, 7 };
				nt = n[INDEX(3)] + int(noteIn);
			} break;
			case Sus2: {
				const int n[] = { 0, 2, 7 };
				nt = n[INDEX(3)] + int(noteIn);
			} break;
			case Sus4: {
				const int n[] = { 0, 5, 7 };
				nt = n[INDEX(3)] + int(noteIn);
			} break;
			case Major7: {
				const int n[] = { 0, 4, 7, 11 };
				nt = n[INDEX(4)] + int(noteIn);
			} break;
			case Minor7: {
				const int n[] = { 0, 3, 7, 10 };
				nt = n[INDEX(4)] + int(noteIn);
			} break;
			case Nineth: {
				const int n[] = { 2, 4, 7 };
				nt = n[INDEX(3)] + int(noteIn);
			} break;
			case Octave: {
				const int n[] = { 0, 12 };
				nt = n[INDEX(2)] + int(noteIn);
			} break;
			case Sharp5: {
				const int n[] = { 0, 4, 8 };
				nt = n[INDEX(3)] + int(noteIn);
			} break;
			case Dim: {
				const int n[] = { 0, 3, 6 };
				nt = n[INDEX(3)] + int(noteIn);
			} break;
			case Sixth: {
				const int n[] = { 0, 3, 9 };
				nt = n[INDEX(3)] + int(noteIn);
			} break;
			default: break;
		}

		u32 outNote = u32(nt) + (12 * oct);
		float value = Utils::noteFrequency(outNote);
		return Value(value, 1.0f, gate);
	}

	void save(JSON& json) override {
		Node::save(json);
		json["note"] = int(note);
		json["chord"] = int(chord);
		json["direction"] = int(chord);
		json["oct"] = oct;
	}

	void load(JSON json) override {
		Node::load(json);
		note = Note(json["note"].get<int>());
		chord = Chord(json["chord"].get<int>());
		direction = Direction(json["direction"].get<int>());
		oct = json["oct"].get<u32>();
	}

	Note note;
	Chord chord;
	Direction direction;
	u32 oct;

private:
	bool gate = false;
	int prevNt, prevRN = -1;
	int prevN = 0, randN = 0;
};

#endif // TWEN_ARP_NODE_H
