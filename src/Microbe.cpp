#include "Microbe.hpp"

Microbe::Microbe(std::shared_ptr<Logger> lgr) : logger(lgr)
{
    
}

Microbe::~Microbe()
{
    logger.reset();
}

std::vector<MicrobePxl> Microbe::GetLoc()
{
    return thisLoc;
}