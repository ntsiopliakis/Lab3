#include "gpiocregisters.hpp" //for GPIOC
#include "rccregisters.hpp"   //for RCC
#include <iostream>

int main()
{
  /*
  RCC::CR::HSEON::On::Set();
  while(RCC::CR::HSERDY::NotReady::IsSet());
  RCC::CFGR::SW::Hse::Set();
  while(!RCC::CFGR::SWS::Hse::IsSet());
  RCC::CR::HSION::Off::Set();
  
  while(RCC::CR::HSIRDY::NotReady::IsSet());
  */
  
  while(RCC::CR::HSIRDY::NotReady::IsSet());
  RCC::PLLCFGR::PLLN0::Set(60);
  RCC::PLLCFGR::PLLM0::Set(15);                       
  RCC::CR::PLLON::On::Set();
  while(RCC::CR::PLLRDY::NotReady::IsSet());
  RCC::CFGR::SW::Pll::Set();
  while(!RCC::CFGR::SWS::Pll::IsSet());
  
  RCC::AHB1ENR::GPIOCEN::Enable::Set() ;
  GPIOC::MODER::MODER5::Output::Set() ;
  
  for(;;)
  {
    GPIOC::ODR::ODR5::High::Set();
    for(int i=0; i<1000000;i++);
    GPIOC::ODR::ODR5::Low::Set();
    for(int i=0; i<1000000;i++);
  }
}
