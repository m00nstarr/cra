#include "gilded_rose.h"

using std::vector;
using std::string;


GildedRose::GildedRose(vector<ItemInterface*>& items) : itemsList(items)
{
}

void GildedRose::updateQuality()
{
	for (int i = 0; i < itemsList.size(); i++)
	{
		itemsList[i]->updateStatus();
	}
}


void LegendaryItem::updateStatus() {
	// Do Nothing
	return;
}

void AgingItem::updateStatus() {

	this->sellIn = this->sellIn - 1;

	if (this->sellIn < 0)
	{
		this->quality += 2;
	}
	else {
		this->quality += 1;
	}

	if (this->quality > 50) {
		this->quality = 50;
	}

	return;
}


void TicketItem::updateStatus() {

	sellIn = sellIn - 1;
	if (sellIn < 0)
	{
		quality = 0;
		return;
	}

	if (quality < 50)
	{
		if (sellIn < 11 && sellIn >= 6)
		{
			quality += 2;
		}
		else if (sellIn < 6)
		{
			quality += 3;
		}
		else {
			quality += 1;
		}
	}
	return;
}

void NormalItem::updateStatus() {
	if (quality > 0)
	{
		quality -= 1;
	}

	sellIn = sellIn - 1;

	if (sellIn < 0)
	{
		if (quality > 0)
		{
			quality -= 1;
		}
	}

	return;
}