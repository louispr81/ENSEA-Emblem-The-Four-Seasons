/*
#include <boost/test/unit_test.hpp>

#include "Jeu.h" // header in local directory
#include "Joueur.h"
#include "Saison.h"
#include "Plateau.h"
#include <iostream> // header in standard library
#include <string>
using namespace state;
using namespace std;

using namespace ::state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
} 

BOOST_AUTO_TEST_CASE(TestJeu)
{
  {
    Jeu jeu;
    BOOST_CHECK_EQUAL(jeu.tour, 1);
    BOOST_CHECK_EQUAL(jeu.gameover, false);
    jeu.updateSaison();
    BOOST_CHECK_EQUAL(jeu.saison.nom, "hiver");

  
    //ex.setX(21);
    //BOOST_CHECK_EQUAL(ex.x, 21);
  }

  {
    //Jeu jeu;
    //jeu.setX21);
    //BOOST_CHECK_LE(ex.x, 32); // Less than equal
    //BOOST_CHECK_GT(ex.x, 11); // Greater than equl
  }
}

 vim: set sw=2 sts=2 et : */
