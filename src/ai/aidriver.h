#ifndef AIDRIVER_H
#define AIDRIVER_H

#include <vector>

#include <stdint.h>

class AIDriver
{
    public:
        AIDriver(int n, uint8_t from, uint8_t to, uint8_t temp);
        virtual ~AIDriver();
        struct BlockMovement_t {
            uint8_t from; uint8_t to;
        };
        std::vector<BlockMovement_t> getStrategy();


    protected:

    private:
        std::vector<BlockMovement_t> m_strategy;
        void genStrategy(int n, uint8_t from, uint8_t to, uint8_t temp);
};

#endif // AIDRIVER_H
