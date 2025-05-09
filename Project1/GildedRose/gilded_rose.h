#pragma once
#include <string>
#include <vector>

class Item
{
public:
    std::string name;
    int sellIn;
    int quality;
    Item(std::string name, int sellIn, int quality) : name{ name }, sellIn{ sellIn }, quality{ quality }
    {
    }

};

class ItemInterface {
public:
    std::string name;
    int sellIn;
    int quality;

    ItemInterface(std::string name, int sellIn, int quality) : name{ name }, sellIn{ sellIn }, quality{ quality }
    {
    }
    virtual void updateStatus() = 0;
};

class LegendaryItem : public ItemInterface {
public :
    LegendaryItem(std::string name, int sellIn, int quality)
        : ItemInterface(name, sellIn, quality)
    {
    }
    void updateStatus() override;
};

class AgingItem : public ItemInterface {
public:
    AgingItem(std::string name, int sellIn, int quality)
        : ItemInterface(name, sellIn, quality)
    {
    }
    void updateStatus() override;
};

class TicketItem : public ItemInterface {
public:
    TicketItem(std::string name, int sellIn, int quality)
        : ItemInterface(name, sellIn, quality)
    {
    }
    void updateStatus() override;
};

class NormalItem : public ItemInterface {
public:
    NormalItem(std::string name, int sellIn, int quality)
        : ItemInterface(name, sellIn, quality)
    {
    }
    void updateStatus() override;
};

class GildedRose
{
public:

    const char* AGED_BRIE = "Aged Brie";
    const char* BACKSTAGE_PASS = "Backstage passes to a TAFKAL80ETC concert";
    const char* SURFURAS = "Sulfuras, Hand of Ragnaros";

    std::vector<ItemInterface*> itemsList;
    GildedRose(std::vector<ItemInterface *>& items);

    void updateQuality();
};