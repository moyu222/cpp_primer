#include <iostream>
#include <memory>

struct destination {};
struct connection {};

connection connect(destination *pd)
{
    std::cout << "open connection." << std::endl;
    return connection();
}

void disconnect(connection c)
{
    std::cout << "close connection." << std::endl;
}

void end_connection(connection *p)
{
    disconnect(*p);
}

void f(destination &d)
{
    std::cout << "直接 connect" << std::endl;
    connection c = connect(&d);
    std::cout << std::endl;
}

void f1(destination &d)
{
    std::cout << "use shared_ptr" << std::endl;
    connection c = connect(&d);
    // std::shared_ptr<connection> sp(&c, end_connection);
    std::shared_ptr<connection> p(&c, [](connection *p) { disconnect(*p); });
    std::cout << std::endl;
}

int main()
{
    destination d;
    f(d);
    f1(d);
    return 0;
}