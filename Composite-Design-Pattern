public Shape[] getPathToRoot(Shape aShape, int depth) {
  Shape[] returnShapes;
  if (aShape == null) {
    if(depth == 0) return null;
    else returnShapes = new Shape[depth];
  }
  else {
    depth++;
    returnShapes = getPathToRoot(aShape.getParent(), depth);
    returnShapes[returnShapes.length - depth] = aShape;
  }    protected NestedShape parent;

	public NestedShape getParent() {
		return this.parent;
	}
	
	public void setParent(NestedShape s) {
		this.parent = s;
	}
	
	public Shape[] getPathToRoot(Shape aShape, int depth) {
		  Shape[] returnShapes;
		  if (aShape == null) {
		    if(depth == 0) return null;
		    else returnShapes = new Shape[depth];
		  }
		  else {
		    depth++;
		    returnShapes = getPathToRoot(aShape.getParent(), depth);
		    returnShapes[returnShapes.length - depth] = aShape;
		  }
		  return returnShapes;
		}
	
	public Shape[] getPath() {
		return getPathToRoot(this, 0);
	}
  return returnShapes;
}

class NestedShape extends RectangleShape {
    private ArrayList<Shape> innerShapes = new ArrayList<>();
    
    public Shape createInnerShape(PathType pt, ShapeType st) {
        Shape innerShape;
        if (st == ShapeType.SQUARE) {
            int sideLength = Math.min(this.width / 4, this.height / 4);
            innerShape = new SquareShape(0, 0, sideLength, this.width, this.height, this.color, this.borderColor, pt);
        } else if (st == ShapeType.RECTANGLE) {
            innerShape = new RectangleShape(0, 0, this.width / 4, this.height / 4, this.width, this.height, this.color, this.borderColor, pt);
        } else {
        	innerShape = new NestedShape(0, 0, this.width / 4, this.height / 4, this.width, this.height, this.color, this.borderColor, pt);
        }
        innerShapes.add(innerShape);
        innerShape.setParent(this);
        return innerShape;
    }
    
    public NestedShape(int x, int y, int width, int height, int panelWidth, int panelHeight, Color fillColor, Color borderColor, PathType pathType) {
        super(x, y, width, height, panelWidth, panelHeight, fillColor, borderColor, pathType);
        createInnerShape(PathType.BOUNCING, ShapeType.RECTANGLE);
    }
    
    public NestedShape(int width, int height) {
        super(0, 0, width, height, Shape.DEFAULT_PANEL_WIDTH, Shape.DEFAULT_PANEL_HEIGHT, Shape.DEFAULT_COLOR, Shape.DEFAULT_BORDER_COLOR, PathType.BOUNCING);
    }
    
    public Shape getInnerShapeAt(int index) {
        return innerShapes.get(index);
    }
    
    public int getSize() {
        return innerShapes.size();
    }
    
    public void draw(Graphics g) {
    	g.setColor(Color.black);
    	g.drawRect(x, y, width, height);
    	g.translate(this.x, this.y);
    	for (Shape j : innerShapes) {
    		j.draw(g);
    		g.setColor(Color.black);
    		g.drawString(j.label, j.x, j.y);
    	}
    	g.translate(0 - this.x, 0 - this.y);
    }
    
    public void move() {
    	path.move();
    	for (Shape k : innerShapes) {
    		k.move();
    	}
    }
    
    public int indexOf(Shape s) {
    	return innerShapes.indexOf(s);
    }
    
    public void addInnerShape(Shape s) {
    	s.setParent(this);
    	innerShapes.add(s);
    }
    
    public void removeInnerShape(Shape s) {
    	s.setParent(null);
    	innerShapes.remove(s);
    }
    
    public void removeInnerShapeAt(int index) {
    	Shape removed = innerShapes.get(index);
    	removed.setParent(null);
    	innerShapes.remove(index);
    }
    
    public ArrayList<Shape> getAllInnerShapes(){
    	return this.innerShapes;
    }
}
