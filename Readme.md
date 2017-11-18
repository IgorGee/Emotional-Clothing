[emotions table]: http://i.imgur.com/i2DKPvF.png "Emotions Table"
[materials]: http://i.imgur.com/itTRcLl.jpg "Materials"
[wave shield]: http://i.imgur.com/GLxlWJJ.jpg "Wave Shield"
[rgb sensor]: http://i.imgur.com/IK1A827.jpg "RGB Sensor"
[lcd]: http://i.imgur.com/u8NLPdG.jpg "LCD"
[button]: http://i.imgur.com/u8NLPdG.jpg "Button"
[finished]: http://i.imgur.com/IV4h7Ai.jpg "Final Product"
[video]: http://i.imgur.com/NeDSLdI.jpg "Video"

# Emotional Clothing

Have you ever looked at someone's shirt and wondered, "What would that shirt sound like?". Of course you have.
Well now you can with this product. By simply hovering this device over someone's shirt or any article of clothing, you too can listen to the hidden melodies in our clothing.

We may not realize it but people often associate certain colors with specific feelings as numerous studies have shown. It's also no secret that music has incredible impact on our current state of emotions as well.
So why not combine these two factors to enhance the vibes they give off?

The colors and songs played will target emitting various emotions such as:

![emotions table]

## How it works

Every shirt will give off a specific HSL value. Based on that value, the device will play a specific song that will give off an atmospheric mood similar to what the color gives off. And LCD Screen will display the Song & Artist, the Mood, and the corresponding HSL value.

The HSL value that the sensor picks up will be classified into one of at least 8 ranges of colors. Depending on the range that HSL value falls under, it will play the corresponding song mapped to that range.

Because the color sensor I have will record RGB values, I will be using a formula to convert the RGB values into their corresponding HSL values.

This device is only intended to be used for solid colored shirts.

## Demo

[![video]](https://www.youtube.com/watch?v=GCqKvXHVLQU)

## Materials

![materials]

*Note*: Despite it being shown in most pictures, I will not be using the RGB LED due to compatibility issues and limited resources available to me given the devices I'm working with. I'm too lazy to resolder things and take the pictures again, so just pretend like the LED isn't there :)

## Assembly

### Construct the [Wave Shield](https://learn.adafruit.com/adafruit-wave-shield-audio-shield-for-arduino/overview)

![wave shield]

* This is probably the most difficult part of this project. Set aside an hour or two to solder this thing and put it together.
* I highly recommend you test out some songs before moving forward.

### Construct and Attach the [RGB Sensor](https://www.adafruit.com/product/1334)

![rgb sensor]

* This part is not difficult at all. Just make sure you read the instructions from Adafruit.
* Again, be sure to test this component individually.

### Attach the LCD Screen

![lcd]

* If you need help assembling this, you can refer to the schematic in this repository, or google your lcd model.

### Attach the button

![button]

* Again, this is fairly straight forward.
* You can't get much information about the wiring from the pictures anymore, so be sure to refer to the schematic.

## Final Product

![finished]
