#include "SearchTree_vorschlag.hpp"

#include "testing_general.hpp"

#include <stdexcept>
#include <iostream>
#include <cstdint>
#include <random>
// #include <queue>


int test_aufgabe() {
	using KEY_TYPE = int;

	static constexpr size_t NUM_ENTRIES = 1000;
	static constexpr size_t laenge_laufzeit = 5 * 1000 * 1000;

	size_t index = 0;
	KEY_TYPE zahlspeicher[NUM_ENTRIES]; // "queue"

	SearchTree<KEY_TYPE> tree;
	const auto genKey = generateKey<KEY_TYPE>;


	// insert <NUM_ENTRIES> unique numbers into tree:
	for (size_t i = 0; i < NUM_ENTRIES; ) {
		const KEY_TYPE zufallszahl = genKey();

		bool doppelt = false;
		for (size_t j = 0; j < i; j++) { // alles nach i ist uninitialisierter Speicher
			if (zahlspeicher[j] == zufallszahl) {
				doppelt = true;
				break;
			}
		}

		if (doppelt == false) {
			zahlspeicher[i++] = zufallszahl;
			tree.insert(zufallszahl);
		}
	}

	std::cout << "Erste Ausgabe: " << tree << "\n";

	for (size_t k = 0; k < laenge_laufzeit; k++) {
		const KEY_TYPE zufallszahl = genKey();

		bool doppelt = false;
		for (size_t j = 0; j < NUM_ENTRIES; j++) {
			if (zahlspeicher[j] == zufallszahl) {
				doppelt = true;
				break;
			}
		}

		if (doppelt == false) {
			tree.deleteNode(tree.search(zahlspeicher[index]));
			zahlspeicher[index] = zufallszahl;
			tree.insert(zufallszahl);
			index++;
			index %= NUM_ENTRIES;
		}
	}

	std::cout << "Zweite Ausgabe: " << tree << "\n";
	return 0;
}