# Fractol

## Introduction

The **Fractol** project is part of the 42 curriculum and aims to introduce students to **graphics programming** and **fractals**. The goal is to generate and visualize fractals using the **MiniLibX** graphical library.

## Objectives

- Understand **complex numbers** and how they apply to fractals.
- Implement fractal generation using **iterative mathematical formulas**.
- Learn to use **MiniLibX** for rendering graphics.
- Handle **keyboard and mouse events** for interactive fractal manipulation.

## Supported Fractals

- **Mandelbrot Set**
- **Julia Set**
- **Other variations (bonus)**

## Implementation Details

- The program is written in **C**.
- Uses **MiniLibX** for graphics rendering.
- Implements **event handling** for zooming and moving within the fractal.
- Includes **color gradients** for improved visualization.

## Compilation & Execution

### Compilation

```bash
make
```

This generates an executable called `fractol`.

### Usage

```bash
./fractol <fractal_name> [optional parameters]
```

#### Examples:

Run the **Mandelbrot** fractal:
```bash
./fractol mandelbrot
```

Run the **Julia** fractal with custom parameters:
```bash
./fractol julia -0.7 0.27015
```

## Controls

- **Arrow Keys**: Move within the fractal.
- **Mouse Scroll**: Zoom in and out.
- **C Key**: Change color scheme.
- **ESC Key**: Exit the program.

## Possible Enhancements

- Add more fractal types such as **Burning Ship**.
- Implement **multithreading** for performance optimization.
- Improve **smooth zooming** and rendering techniques.

## Resources

- [Mandelbrot Set](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Julia Set](https://en.wikipedia.org/wiki/Julia_set)
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx.html)

## Author

This project was completed as part of the **42 School** curriculum.

---

### Disclaimer

This project is for educational purposes only and follows the **42 project guidelines**.
