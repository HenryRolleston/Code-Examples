NestedShape Java Implementation
📜 Overview

This project is a Java implementation of a hierarchical shape system, submitted as part of a university assignment. It defines a nested shape structure, allowing shapes to contain and interact with other shapes within a graphical environment.

The core class, NestedShape, extends RectangleShape and enables the creation of inner shapes with different movement behaviors (PathType) and shapes (ShapeType). The system also supports parent-child relationships, traversal through the shape hierarchy, and rendering.
🛠 Features

✔ Nested Shapes – Shapes can contain other shapes recursively.
✔ Parent-Child Relationship – Tracks parent shapes and allows hierarchical traversal.
✔ Dynamic Shape Creation – Supports squares, rectangles, and nested shapes.
✔ Custom Movement Paths – Shapes move based on their assigned PathType.
✔ Graphical Representation – Uses Graphics for rendering and label display.
✔ Shape Manipulation – Add, remove, and retrieve inner shapes dynamically.
📌 Key Classes
🔹 NestedShape

    Extends RectangleShape, allowing it to contain inner shapes.
    Supports creation, retrieval, movement, and rendering of nested shapes.
    Stores inner shapes in an ArrayList, enabling dynamic management.

🔹 Shape

    Base class representing a drawable and movable shape.
    Provides parent-child hierarchy management (getPathToRoot).

🔹 getPathToRoot(Shape aShape, int depth)

    Retrieves the ancestry of a shape, returning an array leading to the root shape.

📦 Installation & Usage

    Clone the repository:

git clone https://github.com/yourusername/NestedShapeJava.git
cd NestedShapeJava

Compile the program:

javac NestedShape.java

Run the program (if a main class is provided):

    java Main

🎨 Example Usage

NestedShape parentShape = new NestedShape(100, 100);
Shape innerRectangle = parentShape.createInnerShape(PathType.BOUNCING, ShapeType.RECTANGLE);
System.out.println("Inner Shape Index: " + parentShape.indexOf(innerRectangle));

🚀 Future Improvements

    Enhanced Rendering – Improve visual representation with customizable colors.
    More Shape Types – Support for circles, polygons, and complex figures.
    Physics-based Movement – Introduce acceleration and force-based interactions.

📜 Submitted as part of a University Assignment in Java.
💡 For educational purposes and conceptual understanding.
