#include "Strategy.h"
using namespace  std;
using namespace  z3;
/*
 * Implement your search strategy.
 */
void searchStrategy(z3::expr_vector &OldVec)
{ /* Add your code here */
    int size = OldVec.size();
//    cout <<"OldVec.size() = "<< size << endl;
//    for(int i = 0; i < size; i++)
//    {
//        //cout << i << endl;
//        cout << "OldVec[" << i << "] : " << OldVec[i].to_string() << endl;
//    }
    if(size)
    {
        context &c = OldVec[size - 1].ctx();
        expr_vector e(c);
        //cout << "e.size() =" << e.size() << endl;
        e.push_back(OldVec[size - 1]);
        OldVec.pop_back();
        if(e[0].arg(1).bool_value() == true)
        {
            expr x = c.bool_val(false);
            expr y = (e[0].arg(0) == x);
            //cout << y.to_string() << endl;
            OldVec.push_back(y);
        }
        else
        {
            expr x = c.bool_val(true);
            expr y = (e[0].arg(0) == x);
            //cout << y.to_string() << endl;
            OldVec.push_back(y);
        }
        //cout << OldVec[size - 1].to_string() << endl;
    }
}
