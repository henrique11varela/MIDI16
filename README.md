# MIDI16

A MidiFighter inspired midi controller made with arduino.

---

## TO DO

- [x] Prepare multiplexer
- [x] Learn screen
- [ ] Plan menus UML
- [ ] Plan playing modes
  
## Image Showcase

### AllView

![AllView](/other/README/all.png)
---

### TopView

![TopView](/other/README/TopView.jpg)
---

### FrontView

![FrontView](/other/README/FrontView.jpg)
---

### InsideView

![InsideView](/other/README/InsideView.jpg)
---

### InsideCloseUp

![InsideCloseUp](/other/README/InsideCloseUp.jpg)

---

## Pin Table

| Arduino | Multiplexer | Jack  | Switch | Screen | Encoder |
| ------- | ----------- | ----- | ------ | ------ | ------- |
| 2       |             |       |        | SDA    |         |
| 3       |             |       |        | SCK    |         |
| 4       |             |       | L      |        |         |
| 5       |             |       | R      |        |         |
| 6       |             |       |        |        | X       |
| 7       |             |       |        |        | X       |
| 8       |             |       |        |        | X       |
| 9       | Sig         |       |        |        |         |
| 10      | S3          |       |        |        |         |
| 16      | S2          |       |        |        |         |
| 14      | S1          |       |        |        |         |
| 15      | S0          |       |        |        |         |
| A0      |             | Point |        |        |         |
| A1      |             |       |        |        |         |
| A2      |             |       |        |        |         |
| A3      |             |       |        |        |         |

## Button Mapping
![Button Mapping](/other/README/Button_Mapping.png)

## Menu Diagram

![Menu Diagram](/other/README/Menu_Diagram.png)
