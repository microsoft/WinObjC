/* $Id: timer.h,v 1.1 1998/01/22 06:35:00 gjb Exp $ */
#ifndef _TIMER_H_
#define _TIMER_H_

// Programmer:  John P. Russo
// --------------------------
// John Russo has given permission to any of my students to use his
// "timer" class.
//
// Please give full credit to him any time you wish to use this class.
//              Hossein Hakimzadeh   11/5/96

/**************************  timer.cpp  **********************************

    A simple example that shows how C++ classes can be used to implement
    a "Timer" object, which mimics the familiar actions of a stopwatch.

    The code relies heavily on the clock() function defined in the time
    library. The clock() function returns the number of "ticks" that have
    elapsed since a program starts. The size of a "tick" is compiler
    dependent, but for PC compilers is about 1/18 second.

    The problem with the clock function is that it is not convenient to
    use for typical timing operations. The timer class, defined below, by
    contrast, shows that an object-oriented approach to modules can
    provide tools that are natural and easy to use.

= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = */
#include <time.h>

class Timer
{
  //====================  public section  ================================

  //  The functions and/or data in the public section of a class are
  //  accessible to anyone who uses the Timer class.

public:
  Timer();                 // Constructor, used to declare Timer objects
  void   Start();          // Starts a timer object
  void   Stop();           // Stop a timer object
  void   Reset();          // Reset timer object
  int    IsRunning();      // Is the timer object running?
  double ElapsedTime();    // How much time has been recorded?
  double Resolution();     // Shortest measurable amount of time

  //--------------------  private section  -------------------------------

  //  The functions and/or data in the private section of a class are NOT
  //  accessible to those who use the Timer class. They are accessible by
  //  member functions of the class. This allows access to the data to be
  //  carefully controlled.

private:
  long    StartReading;    // Number of ticks when timer object last started.
  long    ElapsedTicks;    // Number of ticks on timer object.
  int     TimerIsRunning;  // 1 if and only if timer object is running.
  double TicksPerSecond()  // This inline function is used to convert
//    {return 18.206481;}    //   "ticks" (returned by clock() ) to seconds.
    {return CLOCKS_PER_SEC;}    //   "ticks" (returned by clock() ) to seconds.
                           // In most UNIX systems this is 1000000
};

/****************************  Start  ************************************

  If the declaration "Timer StopWatch;" has been made, the the call,
  "StopWatch.Start();" is like push the start button of a real stopwatch.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void Timer::Start()
{
  TimerIsRunning = 1;        //  Stopwatch is now running
  StartReading   = clock();  //  Look at internal clock and remember reading
}

/****************************  Stop   ************************************

  Looks at the PC's internal clock and computes the number of ticks that
  have elapsed since the timer was started.

  Note that if a timer is not reset, it can be used to time several events
  and return the elapsed time for the enter set of events.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void Timer::Stop()
{
  TimerIsRunning = 0;                       //  Stop timer object.
  ElapsedTicks += clock() - StartReading;   //  Add elapsed time to the
}                                           //    previous time.

/****************************  Reset  ************************************

  Clears a Timer of previous elapsed times, so that a new event can be
  timed.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void Timer::Reset()
{
  TimerIsRunning = 0;             // Start not yet called.
  ElapsedTicks   = 0;             // No time on timer object yet.
}

/**************************  IsRunning  ************************************

  The data member, "TimerIsRunning" is used to keep track of whether a
  timer is active, i.e. whether an event is being timed. While we want
  those using the timer class to know when a timer is active, we do NOT
  want them to directly access the TimerIsRunning variable. We solve this
  problem, by making TimerIsRunning private and providing the public
  "access function" below.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
int Timer::IsRunning()
{
  return TimerIsRunning;
}

/*************************  ElapsedTime  ***********************************

  This function allows a client to determine the amount of time that has
  elapsed on a timer object. Note that there are two possibilities:

  1)  A timer object has been started and stopped. We can detect this
      case, because the variable "TimerIsRunning" is false.

  2)  A timer object is "running", i.e. is still in the process of timing
      an event. It is not expected that this case will occur as frequently
      as case 1).

  In either case, this function converts ticks to seconds. Note that
  since the function TicksPerSecond() returns a value of type double,
  an implicit type conversion takes place before doing the division
  required in either case.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
double Timer::ElapsedTime()
{
  if ( !TimerIsRunning )                            // Normal case
    return ElapsedTicks/TicksPerSecond();

  else
    return (ElapsedTicks + clock() - StartReading)/TicksPerSecond();
}

/**************************  Resolution  ***********************************

  Althould we have no way of knowing how accurate the internal clock is,
  we can predict its resolution, which is the shortest event that can be
  measured by the clock.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
double Timer::Resolution()
{
  return 1/TicksPerSecond();   //  Note 1 is coverted to 1.0 before division
}

/********************  Timer (constructor) *******************************

  A "constructor" is a special class member function, one which has the
  same name as the class. The "default constructor" is a constructor that
  has no parameters. A constructor is called automatically when an
  instance of a class is declared. For example, the constructor defined
  below is called when the declaration "Timer T;" is executed.

  If the programmer does not write a default constructor, then the
  compiler will generate one automatically. However, by writing the
  constructor below, we provide automatic initialization of timer objects.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
Timer::Timer()
{
  TimerIsRunning = 0;             // Start not yet called.
  ElapsedTicks   = 0;             // No time on timer object yet.
}

#endif /* _TIMER_H_ */
