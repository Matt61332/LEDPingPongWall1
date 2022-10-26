// #include <FastLED.h>

// #define LED_PIN     2
// #define NUM_LEDS    45
// #define BRIGHTNESS  50
// #define LED_TYPE    WS2811
// #define COLOR_ORDER RGB
// CRGB leds[NUM_LEDS];

// #define UPDATES_PER_SECOND 100
// const int WIDTH = 9;
// const int HEIGHT = 5;

// CRGBPalette16 currentPalette;
// TBlendType    currentBlending;


// void setup() {
//     delay( 3000 ); // power-up safety delay
//     FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
//     FastLED.setBrightness(  BRIGHTNESS );

//       randomSeed(analogRead(0));
// }

// int indexManager(int requestedIndex){

//     int realIndex = requestedIndex; 
//     int y = requestedIndex / WIDTH; 
//     int x = requestedIndex % WIDTH; 

//     if(y % 2 == 1){
//         realIndex = WIDTH - 1 - x;
//         realIndex += WIDTH * y;
//     }
//     return realIndex;

// }

// void initialize(){
//     leds[0] = CRGB::White;

//     for(int i = 0; i < NUM_LEDS;i++){
//         leds[i] = CRGB::White;
//         FastLED.show();
//         FastLED.delay(1000 / 20);
//     }
// }

// void black(){
//     for(int i = 0; i < NUM_LEDS;i++){
//         leds[i] = CRGB::Black;
//     }
//         FastLED.show();
//         FastLED.delay(1000);
// }

// class Rain{
//     public:

//         int light;
//         int light2;

//         double x_pos;
//         double y_pos;
        
//         double y_vel;

//         double seconds;
//         double time;

//         bool alive;


//     public:

//     Rain(){
//         alive = false;
//     }
//         void spawn(double x, double vel)
//         {
//             alive = true;
//             x_pos = x;
//             y_pos = 0;
//             light = floor(x_pos) + floor(y_pos) * WIDTH;
//             light2 = light - WIDTH;

//             y_vel = -vel;

//             seconds = 1000/20;
//             time = .001 * seconds;
//         }
    
//         void step()
//         {
//             double deltaY = y_vel * time;
//             double nextY = y_pos - deltaY;

//             y_pos = nextY;

            
//             light = int(floor(x_pos)) + (int(floor(y_pos)) * WIDTH);
//             light2 = light - WIDTH;
//             if(light2 >= NUM_LEDS){
//                 alive = false;
//             }
//         }
// };


// void AnimateRain(Rain *drops){

//     for(int i = 0;i < WIDTH;i++){
//         if(random(20) == 0 && !drops[i].alive){
            
//             drops[i].spawn(i,random(5,15));
//         }
//         drops[i].step();
//     }
// }

// void clear(){
//     for(int i = 0;i<NUM_LEDS;i++){
//         leds[i] = CRGB::Black;
//     }
// }

// void AnimationStep(Rain *drops){
//     clear();
//     for(int i = 0;i < WIDTH;i++){
//         if(drops[i].light >= 0 && drops[i].light < NUM_LEDS ){
//             leds[indexManager(drops[i].light)] = CRGB::Aqua;
//         }
//         if(drops[i].light2 >= 0 && drops[i].light2 < NUM_LEDS ){
//             leds[indexManager(drops[i].light2)] = CRGB::Aqua;
//         }
//     }
// }

// void loop(){

//      black();

//     Rain *drops = new Rain[WIDTH];

//     for(int i = 0;i < WIDTH;i++){
//         drops[i].spawn(i,10);
//     }

//     while(true){
//         AnimateRain(drops);
//         AnimationStep(drops);
//         FastLED.show();
//         FastLED.delay(1000/20);
//     }

// }

// void WaterAnimation(){
//     currentPalette = OceanColors_p;
//     currentBlending = LINEARBLEND; 
// }