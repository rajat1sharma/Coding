#include "stack.h"
using namespace std;
int main()
{
    Stack st = Stack(15);
    for (int i = 0; i < 6; i++)
        st.push(i + 10);
    while (st.size() != 0)
        cout << st.pop() << endl;

    return 0;
}