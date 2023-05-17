#include "aidriver.h"

AIDriver::~AIDriver()
{
    //dtor
}
/** @brief AIDriver
  *
  * @todo: document this function
  */
AIDriver::AIDriver(int n, uint8_t from, uint8_t to, uint8_t temp)
{
    genStrategy(n, from, to, temp);
}
/** @brief getStrategy
  *
  * @todo: document this function
  */
std::vector<AIDriver::BlockMovement_t> AIDriver::getStrategy()
{
    return m_strategy;
}
/** @brief genStrategy
  *
  * @todo: document this function
  */
void AIDriver::genStrategy(int n, uint8_t from, uint8_t to, uint8_t temp)
{
    if (n == 0) {
        return;
    }
    genStrategy(n - 1, from, temp, to);
    m_strategy.push_back({from, to});
    genStrategy(n - 1, temp, to, from);
}
