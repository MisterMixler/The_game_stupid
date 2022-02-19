#include "DeckObject.h"

DeckOfCards::~DeckOfCards()
{
	delete cardBatch;
}

DeckOfCards::DeckOfCards()
{
	int	number = 0;
	cardBatch = new Card[MAX_COUNT_CARD];

	for (int su = 1; su < 5; su++)//Масти. Всего 4 масти
		for (int c1 = 0; c1 < MAX_COUNT_CARD / 4; c1++)
		{   //Заполняем масти
			cardBatch[number].suit = su;//Масть
			cardBatch[number].value = c1 + 6;//Значение
			number++;
		}
	MixCards();
}

void DeckOfCards::MixCards()//mix our deck
{ 
	Card tmp1;
	Card tmp2;
	int	i1, i2;
	srand(time(NULL));
	for (int i = 0; i < 36; i++)
	{
		i1 = rand() % MAX_COUNT_CARD;
		i2 = rand() % MAX_COUNT_CARD;
		tmp1 = cardBatch[i1];
		tmp2 = cardBatch[i2];
		cardBatch[i1] = tmp2;
		cardBatch[i2] = tmp1;
	}

	m_trump = cardBatch[35]; //trump is the last card in our deck 
}

Card DeckOfCards::GiveCard()
{
	pos++;
	return cardBatch[pos-1];
}