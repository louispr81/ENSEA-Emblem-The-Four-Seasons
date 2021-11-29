#include <boost/test/unit_test.hpp>
#include <vector>
#include <string>
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
    State jeuTest;
    //Test tour
    BOOST_CHECK_EQUAL(jeuTest.getTour(), 1);
    jeuTest.tourSuivant();
    BOOST_CHECK_EQUAL(jeuTest.getTour(), 2);
    // Test change saison
    jeuTest.updateSaison();   
    std::cout<<jeuTest.getSaison()<<'\n';
    BOOST_CHECK_EQUAL((*(jeuTest.getSaison())).getId(), ETE);
    jeuTest.updateSaison();
    std::cout<<jeuTest.getSaison()<<'\n';
    BOOST_CHECK_EQUAL((*(jeuTest.getSaison())).getId(), AUTOMNE);
    jeuTest.updateSaison();
    std::cout<<jeuTest.getSaison()<<'\n';
    BOOST_CHECK_EQUAL((*(jeuTest.getSaison())).getId(), HIVER);
    jeuTest.updateSaison();
    std::cout<<jeuTest.getSaison()<<'\n';
    BOOST_CHECK_EQUAL((*(jeuTest.getSaison())).getId(), PRINTEMPS);                    
    // Test gameover
    jeuTest.abandonner(*(jeuTest.getJoueurs(0)));
    BOOST_CHECK_EQUAL(jeuTest.getGameover(), true);

    

    //ex.setX(21);
    //BOOST_CHECK_EQUAL(ex.x, 21);*/
  }

}
/* vim: set sw=2 sts=2 et : */