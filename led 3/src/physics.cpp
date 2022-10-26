// #include <FastLED.h>

// #define LED_PIN     2
// #define NUM_LEDS    45
// #define BRIGHTNESS  100
// #define LED_TYPE    WS2811
// #define COLOR_ORDER RGB
// CRGB leds[NUM_LEDS];

// #define UPDATES_PER_SECOND 100
// const int WIDTH = 9;
// const int HEIGHT = 5;

// void setup() {
//     delay( 3000 ); // power-up safety delay
//     FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
//     FastLED.setBrightness(  BRIGHTNESS );
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

// class Ball{
//     int light;

//     double x_pos;
//     double y_pos;
    
//     double x_vel;
//     double y_vel;
//     double vel;

//     double seconds;
//     double time;

//     double gravity;

//     public:
//         void spawn(double x, double y)
//         {

//             x_pos = x;
//             y_pos = y;
//             light = floor(x_pos) + floor(y_pos) * WIDTH;

//             leds[indexManager(light)] = CRGB::White;

//             x_vel = 0;
//             y_vel = 0;

//             gravity = 30;

//             seconds = 1000/20;
//             time = .001 * seconds;
//         }
    
//         void step()
//         {

            
//             double deltaX = x_vel * time;
//             double deltaY = ((y_vel*time) + ((.5*(-gravity))*(time*time)));

//             double nextX = x_pos + deltaX;
//             double nextY = y_pos - deltaY;

//             double nextXVel = x_vel;
//             double nextYVel = (y_vel + (-gravity*time));

//             if(nextX < 0 || nextX >= WIDTH ||nextY < 0 || nextY >= HEIGHT){
//                 double xToWall;
//                 double yToWall;

//                 if(nextY < 0){
//                     // yToWall = y_pos;
//                     // nextY = -(deltaY + yToWall);

//                     // nextYVel = -sqrt((y_vel *y_vel) + 2 * -gravity * -yToWall);
//                     // nextYVel = sqrt((nextYVel *nextYVel) + 2 * -gravity * nextY);
//                     nextY = y_pos;
//                     nextYVel = -y_vel;
                
//                 }else if(nextY >= HEIGHT){
//                     // yToWall = HEIGHT - y_pos;
//                     // nextY = HEIGHT - deltaY - yToWall;

//                     // nextYVel = -sqrt((y_vel *y_vel) + 2 * gravity * yToWall);
//                     // nextYVel = -sqrt((nextYVel *nextYVel) + 2 * gravity * (deltaY - yToWall));

//                     nextY = y_pos;
//                     nextYVel = -y_vel;
//                 }
//                 if(nextX < 0){
//                     // xToWall = x_pos;
//                     // nextX = deltaX - xToWall;
//                     nextX = x_pos;
//                     nextXVel = -x_vel;
//                 }else if(nextX >= WIDTH){
//                     // xToWall = HEIGHT - x_pos;
//                     // nextX = HEIGHT - deltaX - xToWall;
//                     nextX = x_pos;
//                     nextXVel = -x_vel;

//                 }

//             }

//             x_pos = nextX;
//             y_pos = nextY;

//             x_vel = nextXVel;
//             y_vel = nextYVel;
           

//             int oldLight = light;
//             light = int(floor(x_pos)) + (int(floor(y_pos)) * WIDTH);
//             if(!(light > NUM_LEDS - 1) && !(light < 0)){
                
//                 leds[indexManager(oldLight)] = CRGB::Black;
//                 leds[indexManager(light)] = CRGB::White;
                
//             }

//             while((light > NUM_LEDS - 1) || (light < 0)){
//                 FastLED.delay(1000);
//                 initialize();
//                 }

            
            
//         }

//         void setValues(double xVel, double yVel, double gravity){
//             x_vel = xVel;
//             y_vel = yVel;
//             this->gravity = gravity;
//         }
// };

// void loop(){

//     initialize();
//     black();

//     Ball ball1;
//     Ball ball2;
//     Ball ball3;
//     Ball ball4;

//     ball1.spawn(8, 1.5);
//     ball2.spawn(4, 3);
//     ball3.spawn(2, 1);
//     ball4.spawn(6, 4);

//     ball1.setValues(4,8,10);
//     ball2.setValues(2,-4,3);
//     ball3.setValues(-5,-5,9);
//     ball4.setValues(20,20,20);

//     while(true){
//         ball1.step();
//         ball2.step();
//         ball3.step();
//         ball4.step();
//     }


// }

