/* 
 * @author Austin Stover
 * May 2020
 * This class makes it easier to perform delta timing on an Arduino-compatible microcontroller.
 * 
 * MIT License
 * 
 * Copyright (c) 2020 Austin Stover
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "Delta_Timer.h"

/*
 * Instantiates the delta timer
 * @param period_micros The delta time period in microseconds
 */
Delta_Timer::Delta_Timer(uint64_t period_micros)
{
  period_us = period_micros;
}

/*
 * Checks if the desired period has elapsed--use this with an if() block
 * @return True if the period has passed
 */
uint8_t Delta_Timer::period_passed()
{
  uint64_t deltaTime = micros() - lastDeltaTime;
  if(deltaTime >= period_us)
  {
    lastDeltaTime = micros();
    return true;
  }
  return false;
}

/*
 * Resets delta timer
 */
void Delta_Timer::reset_timer()
{
  lastDeltaTime = micros();
}