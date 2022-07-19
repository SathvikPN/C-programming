#include<stdio.h>

int val = 0xCAFEB;

void reverse_byte_order(int); /* 0xCAFE --> 0xFECA */
void rotate_4bits(int);
int count_bits(int);
int main()
{
    reverse_byte_order(val);
    rotate_4bits(val);
}

void reverse_byte_order(int val)
{
    /* val = ((0xFF & val) << 8) | (val>>8) */
    int result = 0;
    printf("%X [Hex value]\n", val);
    while (val)
    {
        result = (result<<8)|((val)&(0xFF));
        val = val>>8;
        
    }
    printf("%X [Byte_order_reversed]\n\n", result);
    
}

void rotate_4bits(int val)
{
    printf("%X [Hex value]\n", val);
    int result = ((val & 0xF)<<count_bits(val>>4) | (val>>4));
    printf("%X [last_4bit_rotated]\n\n", result);
}


int count_bits(int val)
{
    int count=0;
    while(val)
    {
        count++;
        val = val>>1;
    }
    return count;
}
