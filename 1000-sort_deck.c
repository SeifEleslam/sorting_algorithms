#include "deck.h"

/**
 * get_card_val - Prints an array of integers
 * @card: The array to be printed
 * Return: int
 */
int get_card_val(const deck_node_t *card)
{
	int val = 0, type = 0;

	val = *(card->card->value) == 'A' ? 1 : *(card->card->value) == 'K' ? 150
																		: (int)*(card->card->value);
	val = strcmp(card->card->value, "10") == 0 ? 58 : val;
	type = (card->card->kind + 1) * 200;

	return (val + type);
}

/**
 * compare_cards - Prints an array of integers
 * @card1: The array to be printed
 * @card2: The array to be printed
 * Return: int
 */
int compare_cards(const void *card1, const void *card2)
{
	card1 = *(deck_node_t **)card1;
	card2 = *(deck_node_t **)card2;
	return (get_card_val(card1) - get_card_val(card2));
}

/**
 * sort_deck - Prints an array of integers
 * @deck: The array to be printed
 */
void sort_deck(deck_node_t **deck)
{
	size_t i, size;
	deck_node_t *cards[52], *curr = *deck;

	size = sizeof(cards) / sizeof(deck_node_t *);
	for (i = 0; i < size; i++, curr = curr->next)
		cards[i] = curr;
	qsort(cards, 52, sizeof(deck_node_t *), *compare_cards);
	*deck = *cards, (*cards)->prev = NULL, (*cards)->next = *(cards + 1);
	for (i = 1; i < size - 1; i++)
		cards[i]->next = cards[i + 1], cards[i]->prev = cards[i - 1];
	cards[size - 1]->next = NULL;
}
