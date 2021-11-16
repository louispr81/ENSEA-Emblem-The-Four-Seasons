#include <boost/test/unit_test.hpp>
#include <vector>
#include "../../src/shared/state.h"

using namespace state;
using namespace std;
BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
	BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestStateNamespace)
{
  {
    //State s;
    //BOOST_CHECK_EQUAL(jeu.tour, 1);
   /* jeuTest.abandonner(jeuTest.getJoueurs(0));
    BOOST_CHECK_EQUAL(jeuTest.getGameover(), false);
    jeuTest.tourSuivant();
    BOOST_CHECK_EQUAL(jeuTest.getTour(), 2);
    //ex.setX(21);
    //BOOST_CHECK_EQUAL(ex.x, 21);*/
  }
/*
  //{
    //Jeu jeu;
    //jeu.setX21);
    //BOOST_CHECK_LE(ex.x, 32); // Less than equal
    //BOOST_CHECK_GT(ex.x, 11); // Greater than equl
  }*/
}
/* vim: set sw=2 sts=2 et : */