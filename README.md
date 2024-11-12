# 🌀 Fract-ol
A feature-rich fractal exploration program written in C using MinilibX. Complete with all bonus features! Part of the School 1337 cursus.

## 📋 Project Structure
```
📦 Fract-ol
├── 📂 utils/           # Utility functions
├── 📄 fractol.c       # Main program file
├── 📄 fractol.h       # Header file
├── 📄 my_julia.c      # Julia set implementation
├── 📄 my_mandelbrot.c # Mandelbrot set implementation
├── 📄 Makefile        # Compilation rules
└── 📄 .DS_Store       # macOS system file
```

## 🎯 Description
Fract-ol is a graphical program that generates beautiful fractals. Users can explore different fractal sets, zoom in/out, and modify parameters in real-time to create stunning mathematical visualizations.

## ⚡ Features
### ✨ Multiple Fractal Types:
- 🔄 Mandelbrot Set
- 🌈 Julia Set
- 🎨 Custom Color Palettes
- 🔍 Infinite Zoom
- 🖱️ Interactive Parameters
- ⌨️ Keyboard Controls
### 🎨 Advanced Features (Bonus):
- 🌺 Burning Ship
- 🔍 Smooth Infinite Zoom
- 🌈 Multiple Color Palettes
- 🖱️ Mouse-based Navigation

## 🛠️ Installation
```bash
# Clone the repository
git clone https://github.com/Serghini04/Fract-ol.git

# Navigate to the project directory
cd Fract-ol

# Install MinilibX dependencies (Ubuntu/Debian)
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev

# Compile the program
make
```

## 💻 Usage
```bash
# Launch with specific fractal type
./fractol [fractal_type]

# Available fractal types:
./fractol mandelbrot
./fractol julia [real] [imaginary]
./fractol burningship
```

## 🎮 Controls
```
Mouse Controls:
🖱️ Scroll Up/Down    : Zoom In/Out
🖱️ Left Click       : Set Julia Parameter (Julia Set)
🖱️ Right Click      : Reset View

Keyboard Controls:
⬆️⬇️⬅️➡️ Arrow Keys   : Move View
+/-           : Increase/Decrease Max Iterations
C             : Cycle Color Schemes
R             : Reset View
ESC           : Exit Program
```

## 🎨 Color Schemes
1. 🌈 Rainbow Gradient
2. 🔥 Fire Colors
3. ❄️ Ice Colors
4. 🌙 Night Sky
5. 🌊 Ocean Depths

## ⚙️ Technical Requirements
- C Language
- MinilibX Library
- Norm Compliant (42 School Code Standards)
- No Memory Leaks
- Limited Functions:
  - open, close, read, write
  - malloc, free
  - perror, strerror
  - exit
  - All math library functions
  - All MinilibX functions

## 🔍 Mathematical Concepts
### 1. 📐 Complex Numbers
   - Real and Imaginary Components
   - Complex Plane Mapping

### 2. 🔄 Iteration Formulas
   - Mandelbrot: z = z² + c
   - Julia: z = z² + k

### 3. 📊 Escape-time Algorithm
   - Iteration Counting
   - Boundary Conditions
   - Smooth Coloring

## 🐛 Error Handling
- Invalid Arguments
- Memory Allocation Failures
- Window Creation Errors
- Invalid Parameter Values

## 🚀 Performance Features
- Multi-threaded Rendering
- Calculation Optimization
- Smooth Color Transitions
- Efficient Memory Usage
- Real-time Parameter Control

## 📝 Testing Examples
```bash
# Basic Usage
./fractol mandelbrot

# Julia Set with Parameters
./fractol julia 0.285 0.01

# Other Fractals
./fractol burningship
```

## 📚 Resources
- Fractal Mathematics
- Complex Number Theory
- Computer Graphics
- Color Theory
- MinilibX Documentation

## 🌟 Development Tips
- Implement smooth color transitions
- Optimize calculation loops
- Use proper event handling
- Manage memory carefully
- Test edge cases
- Handle window resizing properly
- Implement efficient zooming

## 🔮 Future Improvements
- Additional Fractal Types
- More Color Schemes
- Save/Load Parameters
- Export Images
- Multi-threading Support
- GUI Controls

--- 

This project is part of the School 1337 curriculum.
