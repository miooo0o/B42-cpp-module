#include "Serializer.hpp"

int main()
{
    Data* data = new Data("Minakim", 8);

    uintptr_t   serialized = Serializer::serialize(data);
    Data*       deserialized = Serializer::deserialize(serialized);

    if (data == deserialized)
        std::cout << "Data is the same" << std::endl;
    else
        std::cout << "Data is different" << std::endl;
    // delete data;
    return (0);
}
