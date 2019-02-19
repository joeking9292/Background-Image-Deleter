# Background-Image-Deleter

This is a Windows desktop application that creates a small window in the top right corner of the screen. In this window, there is one button the size of the window that when pressed, deletes the currently displayed background image.

UPDATE: I'm in the process of adding another button for moving the currently displayed image into a separate folder for the images I really like. The application will most likely not work. The 2 buttons will display but will not be able to do anything yet.


# Why I created this application:

When I first build my desktop back in the Fall of 2015, I realized I needed some background images instead of the usual very blue and black default Windows background we all an love. So I naturally downloaded around 25,000 background images from a bunch of different Imgur albums. Link to where I found those albums: https://imgur.com/gallery/5LHPAuk. I soon realized that I didn't like some of the images being displayed and wanted to delete them from the folder that I had told Windows to randomly select images from. The problem was that I had no way of knowing which image in that folder was being displayed because Windows doesn't tell me the exact file location of the image. Windows will only give me a cached version of the current background image. So I set off to create an application that will use a VBScript (not written by me but modified by me) to get the actual file location of the currently displayed background image and delete it from the folder that image is in.
