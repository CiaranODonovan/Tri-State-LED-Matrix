# Tri-State-LED-Matrix
This was a project I undertook at the end of my first year of studying software development. IT is a Tri State logic 6x6 LED matrix. After being acquainted with the Arduino platform and fundamental physical computing concepts I wanted to undertake a hands on project with minimal components from scratch to get a better understanding of IO driving, electronics and C based programming.



[![Video Title](https://img.youtube.com/vi/kd1d9ueiUFE/0.jpg)](https://www.youtube.com/watch?v=kd1d9ueiUFE)



At this point in time I possessed very few components, and wanted to challenge myself to make something with what I had which included:

-An Arduino nano
-A breadboard
-An assortment of Mono colored LEDs
-A resistor assortment
-Jumper wires
- A digital multimeter



The natural conclusion was to make an LED matrix, but I had the constraints of limited IO ports on a nano, and a lack of an external power supply. 

# Hardware Design Challenges
The nano can only tolerate 200mA load safely, and a maximum of 20mA per GPIO pin to avoid damage. Additionally the nano only has 14 GPIO pins, which would limit me to a 4x3 matrix if I assigned one data pin per LED, even if I used current limiting resistors to avoid exceeding a total of 200mA. 

Instead I used a technique known as "Charlieplexing", a specific form of tri state multiplexing that utilizes the uni-directional property of diodes, and microprocessor's Input, Output and high impedance pin states to create individual logical addressing to LEDs as the specific anode & cathode layout can allow circuits to be created as permutations rather than combinations.

![RegularCharlieplexedArray2](https://github.com/user-attachments/assets/be31fe1a-265e-4404-adee-c3f05e66e425)


This greatly reduces the number of IO ports needed, at the cost of a lower duty cycle scaling inversely with the number of LEDS. the total number of LEDs (N) that can be driven by a specific number of IO pins (P) can be formally expressed as N = P*(P-1). 


Given 14 pins, the maximum numbers of LEDS I could drive would be 14*(14-1) = 182, however the only mount I had was a relatively small breadboard and the duty cycle would be very low, so instead I used 7 pins to drive a 6x6 total of 36 LEDS matrix which fit the breadboard. 

A breadboard is incredibly suboptimal for the layout due to the electrically common rails and I would not recommend it over cheap perfboards, but it's is still doable if its all you have with some complex wiring. 

Subdividing the electrically common breadboard rails into logical rails with jumper cable connections can allow you to space the anode and cathode legs over 3-4 rails of distance by bending them allowing access to the correct data rails, but the leds may tend towards misalignment due to the awkward angles.

To combat this I 3d modelled a very tight fitting case for physical 6x6 matrix dimensions to eradicate any tendency towards misalignment once the matrix was fully wired, and have included the STL file.

# Software Construction
The software is completely from scratch, and the driving works by mapping out the LEDS as unsinged 8 bit integers (1 byte memory instead of 4 bytes for an int) in a logical array where the first digit represents the row of the matrix and second digit represents the column. (E.G 11 is the top left LED address, 66 is the Bottom right LED address). the row and column of an LED can be later retrieved by using :

int y = logicalPos / 10;
int x = logicalPos % 10;

(x and y are stored as ints as offset numbers can exceed a value of 255 or below 0)

for the purpose of creating offsets for the X Y positions of any abstract data structure that needs to be spatially manipulated across the matrix.

Abstract shapes could also be represented as memory efficient arrays in uint8_t (E.G the letter 'A' as : 


![letter_A](https://github.com/user-attachments/assets/376e0713-6c25-41b2-a7db-02b4f3651205)


equates to 16 bytes in program memory compared to an int format of 64 bytes)

Adding some higher level duty cycle equalization and rendering functions that utilize timing, X,Y offsets and shape data pointers arbitrary shapes can be rendered and driven in real time with animation and control over frame rate. 

Due to being relatively new to programming, originally I had used two value arrays of int types to store the data and the sketch used nearly half of the Arduino's program memory. I also had stack overflow issues with many strings of text due to the nano having 2kb of RAM. With this new way of representing the addresses and data the sketch was reduced down to 2.3kb of Program memory and much less ram usage (current string uploaded uses 143 bytes).



Overall this was a challenging project with some trial and error given I had less than a year of experience in programming and no real experience in electronics, However it gave me a great insight into lower level resource management and specialized techniques for certain hardware constraints and platforms. Additionally it founded a more hands on and intuitive understanding of electronic principles and practicalities that let me move on to other projects such as the robot arm and other various electronic utilities I am currently working on.
