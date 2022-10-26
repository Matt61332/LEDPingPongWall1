#include <FastLED.h>

#define LED_PIN1    2
#define LED_PIN2    3 


#define HEIGHT      20
#define WIDTH       15
#define NUM_LEDS    300
#define BRIGHTNESS  100
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB

#define SECTIONS  2
#define AMMOUNT_PER_SECTION  NUM_LEDS / SECTIONS
CRGB leds1[AMMOUNT_PER_SECTION];
CRGB leds2[AMMOUNT_PER_SECTION];

uint8_t LED_PIN[SECTIONS] = {LED_PIN1,LED_PIN2};


#define UPDATES_PER_SECOND 100

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

void initializeLeds(){

    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN1, COLOR_ORDER>(leds1, AMMOUNT_PER_SECTION).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN2, COLOR_ORDER>(leds2, AMMOUNT_PER_SECTION).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );

}

int indexManager(int requestedIndex){

    int realIndex = requestedIndex; 
    int y = requestedIndex / WIDTH; 
    int x = requestedIndex % WIDTH; 

    if(y % 2 == 1){
        realIndex = WIDTH - 1 - x;
        realIndex += WIDTH * y;
    }
    return realIndex;

}

void setColor(int ledNum,CRGB color){

    int actualLedNum = ledNum + 1;
    int section = NUM_LEDS / actualLedNum;
    int ledIndex = indexManager(ledNum - section * AMMOUNT_PER_SECTION);
    if(ledNum < AMMOUNT_PER_SECTION){
        leds1[ledIndex] = color;
    }else{
        leds2[ledIndex] = color;
    }
}

void clearScreen(){
    for(int i = 0;i<NUM_LEDS;i++){
        setColor(i,CRGB::Black);
    }
    FastLED.show();
    FastLED.delay(1000 / 60);
}

void setup() {

    initializeLeds();

    clearScreen();
    
    currentPalette = OceanColors_p;
    currentBlending = LINEARBLEND;
}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    
    for( int i = 0; i < NUM_LEDS; ++i) {
        setColor(i,ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending));
        colorIndex += 3;
    }
}

void initialize(){

    for(int i = 0; i < NUM_LEDS;i++){
        setColor(i,CRGB::White);
        FastLED.show();
        FastLED.delay(1000 / 60);
    }
}

void loop()
{
    
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    
    FillLEDsFromPaletteColors( startIndex);
    
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}