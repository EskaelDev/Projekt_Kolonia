#include "sdl_objects.h"

// Okno bedzie renderowane do
SDL_Window* gWindow = NULL;

// Renderer okna
SDL_Renderer* gRenderer = NULL;
SDL_Renderer* gRenderer2 = NULL;

// Wyswietlane tekstury
SDL_Texture* gTexture = NULL;
SDL_Texture* gTexture2 = NULL;

// Tekstury magazyow
SDL_Texture* Warehouse_I_texture = NULL;
SDL_Texture* Warehouse_II_texture = NULL;
SDL_Texture* Warehouse_III_texture = NULL;
SDL_Texture* Warehouse_IV_texture = NULL;
SDL_Texture* End_Screen_texture = NULL;

// Czworokaty magazynow
SDL_Rect gWarehouse_rect_right;
SDL_Rect gWarehouse_rect_left;
SDL_Rect gWarehouse_rect_centre;

// Viewporty
SDL_Rect LargeViewport;
SDL_Rect LeftViewport;
SDL_Rect RightViewport;

// Czcionka
TTF_Font *gFont = NULL;
TTF_Font *gFont_12 = NULL;

// Kolor tekstu
SDL_Color textC = { 255, 255, 255 };

// Kolor renderowanego tekstu
SDL_Color textColor = { 255, 255, 255, 255 };

// Dzwiek klikania
Mix_Chunk *gClickSound = NULL;
Mix_Music *gBackgroundMusic = NULL;

SDL_Event e;

Magazine WareHouse;

FILE *slot[MAX_SLOTS];

Uint32 Update_CottonPlantation=NULL;
Uint32 Update_ForestersLodge=NULL;
Uint32 Update_GrainFarm=NULL;
Uint32 Update_SpiceFarm=NULL;
Uint32 Update_HuntersHut=NULL;
Uint32 Update_CocoaPlantation=NULL;
Uint32 Update_CattleFarm=NULL;
Uint32 Update_SheepFarm=NULL;
Uint32 Update_Winery=NULL;
Uint32 Update_TobaccoPlantation=NULL;
Uint32 Update_SugarcanePlantationion=NULL;
Uint32 Update_IronMine=NULL;
Uint32 Update_DeepIronMine=NULL;
Uint32 Update_GoldMine=NULL;
Uint32 Update_FistersHut=NULL;
Uint32 Update_StoneMason=NULL;
Uint32 Update_Bakery=NULL;
Uint32 Update_OreRefenery=NULL;
Uint32 Update_GoldSmith=NULL;
Uint32 Update_ButcherShop=NULL;
Uint32 Update_RumDistillery=NULL;
Uint32 Update_Clothiers=NULL;
Uint32 Update_TobaccoProduction=NULL;
Uint32 Update_WeavingMill=NULL;
Uint32 Update_WeavingHut=NULL;
Uint32 Update_ToolSmithy=NULL;
Uint32 Update_WindMill=NULL;
Uint32 Update_Money = NULL;
Uint32 Update_lvlStat = NULL; 
Uint32 Update_People_LVL = NULL;