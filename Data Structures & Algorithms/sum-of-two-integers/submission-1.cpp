class Solution {
public:
    int getSum(int a, int b)
    {
        int carry=0, output=0, mask=0xFFFFFFFF;

        for(int i=0; i<32; i++)
        {
            int a_bit = (a >> i) & 1;
            int b_bit = (b >> i) & 1;

            int curr_bit = a_bit ^ b_bit ^ carry;
            carry = (a_bit + b_bit + carry) >= 2 ? 1 : 0;

            if(curr_bit)
            {
                output |= (1 << i);
            }
        }

        if(output > 0x7FFFFFFF)
        {
            output = ~(output ^ mask);
        }

        return output;
    }
};
