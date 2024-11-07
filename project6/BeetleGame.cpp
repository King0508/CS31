//
//  BeetleGame.cpp
//

#include "BeetleGame.h"
#include "BeetleDrawing.h"


#include <iostream>

namespace cs31
{

BeetleGame::BeetleGame() : mHuman(), mComputer(), mHumanDie(), mComputerDie()
{
    
}

// draw the board by using a BeetleDrawing to draw the two Beetles
std::string BeetleGame::display( std::string msg ) const
{
    BeetleDrawing drawing( mHuman, mComputer );
    std::string result = drawing.draw() + "\n" + msg;
    return( result );
}


// TODO when amount is zero, it is a random roll...
// otherwise, an amount value is a cheating value...
void BeetleGame::humanRoll( int amount )
{   
    if (amount == 0)
    {
        mHumanDie.roll(); 

    }
    else
    {
        mHumanDie.setValue(amount);
    }
    // if the amount is zero, roll the Human's die
    // otherwise, cheat by forcing the amount into the Human's die
}

// TODO return the value of the Human's die
int BeetleGame::getHumanDie( ) const
{
    return(mHumanDie.getValue());
}

// TODO convert the Human's die value to a Beetle's body part
// then depending on the body part involved, enforce the game ordering of body parts:
// - namely, body before everything else and head before eyes or antenna
// if allowed, build the desired body part on the Human's beetle
// if a body part was successfully built, return true
// otherwise, return false
bool BeetleGame::humanPlay( )
{
    bool play;
    Beetle::BodyPart human = mHuman.convertRollToBodyPart(getHumanDie());
    switch (human)
    {
    case Beetle::BodyPart::BODY:
        if (mHuman.hasBody() == false)
        {
            mHuman.buildBody();
            play = mHuman.hasBody();
        }
        else
        {
            play = false;
        }
        break;
    case Beetle::BodyPart::HEAD:
        if (mHuman.hasHead() == false && mHuman.hasBody())
        {
            mHuman.buildHead();
            play = mHuman.hasHead();
        }
        else
        {
            play = false;
        }
        break;
    case Beetle::BodyPart::TAIL:
        if (mHuman.hasTail() == false && mHuman.hasBody())
        {
            mHuman.buildTail();
            play = mHuman.hasTail();
        }
        else
        {
            play = false;
        }
        break;
    case Beetle::BodyPart::ANTENNA:
        if (mHuman.hasAntenna1() == false && mHuman.hasHead())
        {
            mHuman.buildAntenna();
            play = mHuman.hasAntenna1();

        }
        else if (mHuman.hasAntenna2() == false && mHuman.hasHead())
        {
            mHuman.buildAntenna();
            play = mHuman.hasAntenna2();
        }
        else
        {
            play = false;
        }
        break;
    case Beetle::BodyPart::EYE:
        if (mHuman.hasEye1() == false && mHuman.hasHead())
        {
            mHuman.buildEye();
            play = mHuman.hasEye1();
        }
        else if (mHuman.hasEye2() == false && mHuman.hasHead())
        {
            mHuman.buildEye();
            play = mHuman.hasEye2();
        }
        else
        {
            play = false;
        }
        break;
    case Beetle::BodyPart::LEG:
        if (mHuman.hasLeg1() == false && mHuman.hasBody())
        {
            mHuman.buildLeg();
            play = mHuman.hasLeg1();
        }
        else if (mHuman.hasLeg2() == false && mHuman.hasBody())
        {
            mHuman.buildLeg();
            play = mHuman.hasLeg2();
        }
        else if (mHuman.hasLeg3() == false && mHuman.hasBody())
        {
            mHuman.buildLeg();
            play = mHuman.hasLeg3();
        }
        else if (mHuman.hasLeg4() == false && mHuman.hasBody())
        {
            mHuman.buildLeg();
            play = mHuman.hasLeg4();
        }
        else
        {
            play = false;
        }
        break;
    case Beetle::BodyPart::NOTVALID:
        play = false;
        break;
    default:
        play = false;

    } 
    return(play);
}

// TODO when amount is zero, it is a random roll...
// otherwise, an amount value is a cheating value...
void BeetleGame::computerRoll( int amount )
{
    if (amount == 0)
    {
        mComputerDie.roll();

    }
    else
    {
        mComputerDie.setValue(amount);
    }
}

// TODO return the value of the Computer's die
int BeetleGame::getComputerDie( ) const
{
    return(mComputerDie.getValue());
}

// TODO convert the Computer's die value to a Beetle's body part
// then depending on the body part involved, enforce the game ordering of body parts:
// - namely, body before everything else and head before eyes or antenna
// if allowed, build the desired body part on the Computer's beetle
// if a body part was successfully built, return true
// otherwise, return false
bool BeetleGame::computerPlay( )
{
    bool play;
    Beetle::BodyPart computer = mComputer.convertRollToBodyPart(getComputerDie());
    switch (computer)
    {
    case Beetle::BodyPart::BODY:
        if (mComputer.hasBody() == false)
        {
            mComputer.buildBody();
            play = mComputer.hasBody();
        }
        else
        {
            play = false;
        }
        break;
    case Beetle::BodyPart::HEAD:
        if (mComputer.hasHead() == false && mComputer.hasBody())
        {
            mComputer.buildHead();
            play = mComputer.hasHead();
        }
        else
        {
            play = false;
        }
        break;
    case Beetle::BodyPart::TAIL:
        if (mComputer.hasTail() == false && mComputer.hasBody())
        {
            mComputer.buildTail();
            play = mComputer.hasTail();
        }
        else
        {
            play = false;
        }
        break;
    case Beetle::BodyPart::ANTENNA:
        if (mComputer.hasAntenna1() == false && mComputer.hasHead())
        {
            mComputer.buildAntenna();
            play = mComputer.hasAntenna1();

        }
        else if (mComputer.hasAntenna2() == false && mComputer.hasHead())
        {
            mComputer.buildAntenna();
            play = mComputer.hasAntenna2();
        }
        else
        {
            play = false;
        }
        break;
    case Beetle::BodyPart::EYE:
        if (mComputer.hasEye1() == false && mComputer.hasHead())
        {
            mComputer.buildEye();
            play = mComputer.hasEye1();
        }
        else if (mComputer.hasEye2() == false && mComputer.hasHead())
        {
            mComputer.buildEye();
            play = mComputer.hasEye2();
        }
        else
        {
            play = false;
        }
        break;
    case Beetle::BodyPart::LEG:
        if (mComputer.hasLeg1() == false && mComputer.hasBody())
        {
            mComputer.buildLeg();
            play = mComputer.hasLeg1();
        }
        else if (mComputer.hasLeg2() == false && mComputer.hasBody())
        {
            mComputer.buildLeg();
            play = mComputer.hasLeg2();
        }
        else if (mComputer.hasLeg3() == false && mComputer.hasBody())
        {
            mComputer.buildLeg();
            play = mComputer.hasLeg3();
        }
        else if (mComputer.hasLeg4() == false && mComputer.hasBody())
        {
            mComputer.buildLeg();
            play = mComputer.hasLeg4();
        }
        else
        {
            play = false;
        }
        break;
    case Beetle::BodyPart::NOTVALID:
        play = false;
        break;
    default:
        play = false;

    }
    return(play);
}

// TODO what is the current state of the game
BeetleGame::GameOutcome  BeetleGame::determineGameOutcome( ) const
{
    GameOutcome result; 
    if (mHuman.isComplete())
    {
        result = GameOutcome::HUMANWONGAME;
    }
    else if (mComputer.isComplete())
    {
        result = GameOutcome::COMPUTERWONGAME;
    }
    else
    {
        result = GameOutcome::GAMENOTOVER;
    }
    return(result);
}

std::string  BeetleGame::stringifyGameOutcome( ) const
{
    std::string result = "";
    switch( determineGameOutcome() )
    {
        case GameOutcome::COMPUTERWONGAME:
            result = "Computer Won!";
            break;
        case GameOutcome::HUMANWONGAME:
            result = "Human Won!";
            break;
        case GameOutcome::GAMENOTOVER:
            result = "Game Not Over!";
            break;
    }
    return( result );
}

// TODO has the game ended with a winner?
bool BeetleGame::gameIsOver() const
{
    bool over = false; 
    if (determineGameOutcome() == GameOutcome::HUMANWONGAME || determineGameOutcome() == GameOutcome::COMPUTERWONGAME)
    {
        over = true; 
    }
    return(over);
}


Beetle BeetleGame::getHumanBeetle( ) const
{
    return( mHuman );
}

Beetle BeetleGame::getComputerBeetle( ) const
{
    return( mComputer );
}

}


