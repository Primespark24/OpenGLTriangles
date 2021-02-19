# Project 1 - Initial Program Specifications
Whitworth University - CS-357 Computer Graphics  
Last edited: 2/19/2021 by Scott  

## Overview

The goal of this first project is to prove that you have your environment set up and working. Additionally you are going to show that you can modify the code in novel ways.

You can do this assignment in whatever Graphics Language you like, but you need to approach the theme of the original assignment if not doing it in OpenGL. If you have questions on how this will work, let me know and we can clarify the standard.

## Grade

| Portion             | Points Possible |
|---------------------|-----------------|
| Chapter 2 Code      | 20              |
| Adaptation          | 40              |
| Proof               | 40              |

Please only upload original code and documentation! I don't want to see whole libraries uploaded or zip files unrelated to what you did. You should use a good `.gitignore` file, if you don't know what that is, let me know and I can show you.

## Part 1: Chapter 2 Code  
Using the sb7 interface and the Chapter 2 initial program, re-implement the last triangle-over-changing-color program. Your end result needs to be a solidly colored triangle over a changing color background.

You need to go back to CS1 level commenting. You need to prove to me know you what you are doing, not just copy-pasting. Every line of code needs to have a comment and every function call needs to have the arguments defined in the context of what you are doing.

If you have a line like: `glClearBufferfv(GL_COLOR, 0, color);` you need to have a comment(s) that describes what `glClearBufferfv` does, what each of the arguments are and why you are passing in `(GL_COLOR, 0, color)`. The book is your friend here, but don't just copy/paste the words from the book, use your own words to describe these things.

## Adaptation
Take your code from above and do something creative with it.

I know this is week 1 of graphics, so your tool belt is relatively limited. That is fine. Look around sb7.h, look at the methods that are exposed. Look at the methods and shaders you used in part 1 and think about how you could modify the code to do something different and interesting. 

In about 15 mins I figured out how to have the color change based on my mouse position.

I know this is an open ended question. I am asking you to be creative. The grade for this portion will be reflective of the creativity, documentation and effort involved

**To be clear: you should be turning in two different pieces of code! One that is for part1 and one that is for part2**

## Proof
I don't really want to have to compile your code, especially when considering that many of you will be using your own environments.

You need to submit, with your above code, video documentation of your program working. This could be a gif, this could be a mpg4, this could be a youtube link. I don't care, you are in charge. 

I would suggest going the OBS -> YouTube route. Works pretty well. Having a YouTube account for this class is going to make your life a little easier down the line anyway.
