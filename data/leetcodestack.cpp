#include <bits/stdc++.h>
using namespace std;


typedef struct Stack{
    int data;
    struct Stack* next;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack S;
    S = (MinStack)malloc(sizeof(struct Stack));
    S->next = NULL;
    return S;
}

void minStackPush(MinStack* obj, int x) {
    
}

void minStackPop(MinStack* obj) {
    
}

int minStackTop(MinStack* obj) {
    
}

int minStackGetMin(MinStack* obj) {
    
}

void minStackFree(MinStack* obj) {
    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */







 public boolean isValid(String s) {
	Stack<Character> stack = new Stack<Character>();
	for (char c : s.toCharArray()) {
		if (c == '(')
			stack.push(')');
		else if (c == '{')
			stack.push('}');
		else if (c == '[')
			stack.push(']');
		else if (stack.isEmpty() || stack.pop() != c)
			return false;
	}
	return stack.isEmpty();
}

if (stack.empty() || stack.top()!='(') 
    return false; 
else 
    stack.pop(); 






public class Color //颜色类
{
private int value; //颜色值
public Color(int red, int green, int blue) //构造方法
{
value = 0xff000000 | ((red & 0xFF)<<16) | ((green & 0xFF)<<8) | blue & 0xFF;
}
public Color(int rgb)
{
value = 0xff000000 | rgb;
}
public int getRGB()
{
return value;
}
public int getRed()
{
return (getRGB()>>16) & 0xFF;
}
public int getGreen()
{
return (getRGB()>> 8) & 0xFF;
}
public int getBlue()
{
return getRGB() & 0xFF;
}
public String toString()
{
return getClass().getName()+",RGB("+getRed()+","+getGreen()+","+getBlue()+"),0x"
+Integer.toHexString(value);
}
public static void main(String args[])
{
System.out.println(new Color(255,0,0).toString()); //红
System.out.println(new Color(0,255,0).toString()); //绿
System.out.println(new Color(0,0,255).toString()); //蓝
System.out.println(new Color(255,255,255).toString()); //白
}

}