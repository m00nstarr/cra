#include "gmock/gmock.h"
#include "gilded_rose.h"

using std::vector;
using std::string;


class ItemClassFixture : public testing::Test {
public:

    GildedRose* app;

    void SetUp() override {
        std::vector<ItemInterface *> items;

        items.push_back(new NormalItem( "+5 Dexterity Vest", 10, 20 ));
        items.push_back(new AgingItem{ "Aged Brie", 2, 0 });
        items.push_back(new NormalItem{ "Elixir of the Mongoose", 5, 7 });
        items.push_back(new LegendaryItem{ "Sulfuras, Hand of Ragnaros", 0, 80 });
        items.push_back(new LegendaryItem{ "Sulfuras, Hand of Ragnaros", -1, 80 });
        items.push_back(new TicketItem{ "Backstage passes to a TAFKAL80ETC concert", 15, 20 });
        items.push_back(new TicketItem{ "Backstage passes to a TAFKAL80ETC concert", 10, 49 });
        items.push_back(new TicketItem{ "Backstage passes to a TAFKAL80ETC concert", 5, 49 });

        app = new GildedRose(items);
    }

    void TearDown() override {
        delete app;
    }
};

TEST_F(ItemClassFixture, InterfaceMethodTestDay20) {
    for (int i = 0; i < 20; i++) {
        app->updateQuality();
    }
    //Arrange
    EXPECT_EQ(38, app->itemsList[1]->quality);
    EXPECT_EQ(0, app->itemsList[2]->quality);
    EXPECT_EQ(80, app->itemsList[3]->quality);
    EXPECT_EQ("Aged Brie", app->itemsList[1]->name);
}

TEST_F(ItemClassFixture, InterfaceMethodTestDay30) {
    //Act
    for (int i = 0; i < 50; i++) {
        app->updateQuality();
    }
    //Arrange
    EXPECT_EQ(50, app->itemsList[1]->quality);
    EXPECT_EQ(0, app->itemsList[2]->quality);
    EXPECT_EQ(80, app->itemsList[3]->quality);
}