---
title: "FluffelBot Controller"
github: "https://github.com/Flockemon24/FluffelBot-Controller"
description: "Motor controller for the FluffelBot. Can control up to four motors independently. "
created_at: "2026-11-01"
total_time: "29h"
---

# FluffelBot-Controller – devlog

> A simple Motorcontroller with an ESP32 and two TB6612FNG to control four wheels.

| Tier | Hours logged | Entries |
| --- | --- | --- |
| Tier 3 | 29h | 4 |

## Contents

1. [2026-10-06 – I designed the PCB](#-October-6,-2026:-October-6,-2026---I-designed-the-PCB)
2. [2026-10-10 – I programmed the firmware for the ESP32](#-October-10,-2026:-October-10,-2026---I-programmed-the-firmware-for-the-ESP32)
3. [2026-10-10 – Looked up items I need on Amazon.com](#-October-10,-2026-(entry-2):-October-10,-2026---Looked-up-items-I-need-on-Amazon.com)
4. [2026-10-10 – Looked up items I need on Amazon.com](#-November-9,-2026:-November-9,-2026---Fixed-few-problems-before-review)

## Design

# October 6, 2026: October 6, 2026 - I designed the PCB
<!-- fabricate:entry 1789 -->

In this session, I designed the whole PCB for the motor control. I used some inspiration from other GitHub-Repositories, so I can make sure my PCB will work. After I designed everything in EasyEDA I added all the files to my GitHub. 

The project uses two simple dual motor drivers (TB6612FNGs) to control four motors independently and also includes a IMU sensor (the BMI160) to know where it is (rotation/speed) as well as a battery protection with fuses.

For a overview of the project, i first wrote a presentation (or sth like that ;-)) and then used EasyEDA for routing the things.
Because the ESP32 has other free pins, I thought it would be nice to dont waste them, so I added plugs to the PCB, so its possible to use those pins I didnt use for motor control too.

Next steps to do are writing the firmware and a BOM.

![PCB 3d View](https://fabricate.hackclub-assets.com/8be382e367be8dd9586f58f97bb4f28180af7b2844cf420db19d1bbc4afd4b6f/image-png/8be382e367be8dd9586f58f97bb4f28180af7b2844cf420db19d1bbc4afd4b6f.png)

![PCB_FluffelBot-Controller](https://fabricate.hackclub-assets.com/69f4cf4343385a5544465ad3d2d29e8a074167fc89fc5515c0dad5b77b608916/image-png/69f4cf4343385a5544465ad3d2d29e8a074167fc89fc5515c0dad5b77b608916.png)

![SCH_PCB_FluffelBot-Controller](https://fabricate.hackclub-assets.com/3c29c09232b79185c84a3f99facab64b69de45e02428080040e8820588d42e5f/image-png/3c29c09232b79185c84a3f99facab64b69de45e02428080040e8820588d42e5f.png)

![image](https://fabricate.hackclub-assets.com/26fa46a25f4ae7635a08c9194231fa65fdaaabe305253f70046953aa5633378f/image-png/26fa46a25f4ae7635a08c9194231fa65fdaaabe305253f70046953aa5633378f.png)

![image](https://fabricate.hackclub-assets.com/501cebac53269d9aa2dbcfd8e3c7a6a08ce09641cdec3d8ce783544e95e3c0b5/image-png/501cebac53269d9aa2dbcfd8e3c7a6a08ce09641cdec3d8ce783544e95e3c0b5.png)

![image](https://fabricate.hackclub-assets.com/5f05ffca41456632162f45e9fd4c0e2fbc79b962ec9048aefffc6e859e75c881/image-png/5f05ffca41456632162f45e9fd4c0e2fbc79b962ec9048aefffc6e859e75c881.png)

![image](https://fabricate.hackclub-assets.com/2eab2d0c32d52d67b41f787d18c7f48231d84ed2cb8c2171586c53df4b8f8a81/image-png/2eab2d0c32d52d67b41f787d18c7f48231d84ed2cb8c2171586c53df4b8f8a81.png)

![image](https://fabricate.hackclub-assets.com/ecfc228c3bfc0da06337cd4caee2bb301a8eeba8fbf2295e5ab7654d58a8d3d3/image-png/ecfc228c3bfc0da06337cd4caee2bb301a8eeba8fbf2295e5ab7654d58a8d3d3.png)

![image](https://fabricate.hackclub-assets.com/8efbf40f5f9468cf7160ea34b3ab8724a8d74eb67c3ff5f5fcb1fbb526a93c02/image-png/8efbf40f5f9468cf7160ea34b3ab8724a8d74eb67c3ff5f5fcb1fbb526a93c02.png)

![image](https://fabricate.hackclub-assets.com/118736ca5e11ef75d6ff05609f05976c90ec34ff9a56dddf50d1409604cef4c6/image-png/118736ca5e11ef75d6ff05609f05976c90ec34ff9a56dddf50d1409604cef4c6.png)

![image](https://fabricate.hackclub-assets.com/a5b05c7a2fb95d4e74e63c1d0434c6aa0cc7db5d9dda5e9d10e6c7dc7c901149/image-png/a5b05c7a2fb95d4e74e63c1d0434c6aa0cc7db5d9dda5e9d10e6c7dc7c901149.png)

**Total time spent: 11h**

# October 10, 2026: October 10, 2026 - I programmed the firmware for the ESP32
<!-- fabricate:entry 1790 -->

In this session, I programmed the firmware for the ESP32 so that it can really control the motor drivers. It took a long time to initialize PlatformIO in Visual Studio Code but after three hours it finally worked. Then I restructured the project structure and added everything to GitHub.

The code is very simple:
It uses the `ledc.h` library from the *Arduino Library Manager.*
There are two self-programmed functions, `setMotor` and `stopAll`, to (obviously) set the motors to a specific speed, and to stop them all.

The example code initializes the motors first and then let them start.


![image](https://fabricate.hackclub-assets.com/3053918f10fefcedf25b9f0d7abcb0102db9b71e6943538f07f8217fa6c5ffe4/image-png/3053918f10fefcedf25b9f0d7abcb0102db9b71e6943538f07f8217fa6c5ffe4.png)

![image](https://fabricate.hackclub-assets.com/f1be4c13051c4ce4a4b019a08406645489e0b27e0d1d7d6599b799d8d35f60f5/image-png/f1be4c13051c4ce4a4b019a08406645489e0b27e0d1d7d6599b799d8d35f60f5.png)

![image](https://fabricate.hackclub-assets.com/33d95941679af29b9a086e2ed3ba6d4e6eed0d0db2052f96c158523a235a51d4/image-png/33d95941679af29b9a086e2ed3ba6d4e6eed0d0db2052f96c158523a235a51d4.png)

![image](https://fabricate.hackclub-assets.com/dcf4c2d7846a03bf9543aef06e21b7dbf96fc4af375111ab03b01fa89e05166c/image-png/dcf4c2d7846a03bf9543aef06e21b7dbf96fc4af375111ab03b01fa89e05166c.png)

![image](https://fabricate.hackclub-assets.com/a4ab74861ef2c6dcbc4f15dbb1f87354f486c1abbd966f2361273775fbebe70a/image-png/a4ab74861ef2c6dcbc4f15dbb1f87354f486c1abbd966f2361273775fbebe70a.png)

![image](https://fabricate.hackclub-assets.com/fb846f9eb863f987f3c72d29caef836b2da2a7f3c4d3d4d075f64e06d59fafc9/image-png/fb846f9eb863f987f3c72d29caef836b2da2a7f3c4d3d4d075f64e06d59fafc9.png)

![image](https://fabricate.hackclub-assets.com/45f5d419306b8763141c655352e1232c932ab9d42b4d15c7c517596f1ae26c30/image-png/45f5d419306b8763141c655352e1232c932ab9d42b4d15c7c517596f1ae26c30.png)

![image](https://fabricate.hackclub-assets.com/35400ffd36335f1308404040962175df2d0e0a3602e341f9ab0c260a26568fcc/image-png/35400ffd36335f1308404040962175df2d0e0a3602e341f9ab0c260a26568fcc.png)

![image](https://fabricate.hackclub-assets.com/5544e61f18357d8fd5fb4609be76a126bcce3c6746c759f00fd0acb52cb11ed8/image-png/5544e61f18357d8fd5fb4609be76a126bcce3c6746c759f00fd0acb52cb11ed8.png)

**Total time spent: 9h**

# October 10, 2026 (entry 2): October 10, 2026 - Looked up items I need on Amazon.com
<!-- fabricate:entry 1791 -->

In this session, I looked for the items I need to build the PCB. I found everything on Amazon.com and linked the things. Because I was fist over the funding limit, I chose the higher limit. Shipping on Amazon.com is free.
I choose those links because they are much cheaper when you buy them as a pack of more then one part. Thats why I have like 3 IMUs, 10 MINI560 and even more fuses. 
I need the following parts:
- **ESP32**
- **2x TBFN6612FNG** (Motor driver)
- **BMI160** (IM-Unit)
- **LiPo Pack for Power Supply**
- a few Pin **Headers** and **Plugs**

---

![image](https://fabricate.hackclub-assets.com/9bea927025e13c345201ba509e54ceaf4898e1e157d4d69070589f46be86dbae/image-png/9bea927025e13c345201ba509e54ceaf4898e1e157d4d69070589f46be86dbae.png)

![image](https://fabricate.hackclub-assets.com/cf8405372c8b6aefe248812e9cb6d3de9394833c15ad4ab3ea314804fce752c4/image-png/cf8405372c8b6aefe248812e9cb6d3de9394833c15ad4ab3ea314804fce752c4.png)

![image](https://fabricate.hackclub-assets.com/50c3355bdaa931c3a3db9a0bcff09b761e3c0a0f2390914a6700f1707f9dcd6c/image-png/50c3355bdaa931c3a3db9a0bcff09b761e3c0a0f2390914a6700f1707f9dcd6c.png)

![Cart-Amazon-FluffelBot-Controller](https://fabricate.hackclub-assets.com/9bea927025e13c345201ba509e54ceaf4898e1e157d4d69070589f46be86dbae/image-png/9bea927025e13c345201ba509e54ceaf4898e1e157d4d69070589f46be86dbae.png)

![image](https://fabricate.hackclub-assets.com/2b503101e91d669224ba54012b3d5e0477ad72981f6891198f0695c223f2a512/image-png/2b503101e91d669224ba54012b3d5e0477ad72981f6891198f0695c223f2a512.png)

![image](https://fabricate.hackclub-assets.com/46766983a8147ebde21b176365fecdcdc16f952f46861c79d1e381e5cb3bdaa0/image-png/46766983a8147ebde21b176365fecdcdc16f952f46861c79d1e381e5cb3bdaa0.png)

![image](https://fabricate.hackclub-assets.com/471183037678f2d48d19b20759fbaab4939506998f745932bb36ad4182d6c6d1/image-png/471183037678f2d48d19b20759fbaab4939506998f745932bb36ad4182d6c6d1.png)

![Shopping-Cart](https://fabricate.hackclub-assets.com/0d00333885bec6610034f0f0bfa84ab788d94d02efce4b0467c27bebcc74c20a/image-png/Screenshot%202026-10-24%20172434.png)

**Total time spent: 8h**

# November 9, 2026: November 9, 2026 - Fixed few problems before review
<!-- fabricate:entry 2507 -->

I fixed the problems before I can review again:
- I wrote longer texts to every journal entry so the time I have logged is justified.
- I edited the `BOM.csv`. Now I only linked 1 ESP32 and not 10 MINI560 however the other parts are much, much cheaper when you buy it as a pack.

![MINI560](https://fabricate.hackclub-assets.com/218c95ffc34d400fc9183d917bd80f01b53a2a4761ca26726f45dff65bea75ca/image-png/image.png)

![](https://fabricate.hackclub-assets.com/8adb31addb3a88ba1e72ab571e22bced3106299794986bf9cc1b0d8ac63b4457/image-png/Cart-Amazon-FluffelBot-Controller-v3.png)

**Total time spent: 1h**
