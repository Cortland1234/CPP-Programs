//
// ASSIGNMENT A-06: STRATEGY
//
// Demonstrates the Strategy Pattern
//
// NAME: Cortland Diehm
// CLASS: CSCV 335
// DATE: 4/16/2023
// INSTRUCTOR: Fred D'Angelo
//

#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <iterator>
#include <cmath> // for math

using std::cout;   // prefered to: using namespace std;
using std::endl;
using std::setprecision;
using std::string;
using std::list;
using std::pow;

class My_Math
{
public:
 	static double round( double value, double decimalPlaces)
	{
		double adder ;
	 
		double multiplierDivisor ;

		int    intValue ;

		adder = 5.0 / pow( 10, (decimalPlaces + 1)) ;

		value = value + adder ;

		multiplierDivisor = pow( 10, decimalPlaces ) ;

		value = value *  multiplierDivisor ;

		intValue = ( int ) value ;

		value = ( double ) intValue ;

		return value  / multiplierDivisor ;
	}
};

class Investment_Return
{
public:
	virtual double evaluate_return( ) = 0 ; // pure virtual method, exists to be overridden

	virtual string toString() = 0 ; // pure virtual method, exists to be overridden
};
        
class Pay_Back : public Investment_Return
{	
private:
	double investment ;
	double annual_return;
	
public:
	Pay_Back( double , double ) ;

    double evaluate_return() override;
	
	string toString();
};

Pay_Back::Pay_Back( double investment, double annual_return) 
{
	this->investment = investment ;
	
	this->annual_return = annual_return ;
}

double Pay_Back::evaluate_return()
{
	return investment / annual_return ;
}

string Pay_Back::toString()
{
	string my_state ;
	
	my_state = "\nGiven: investment      = " + std::to_string(investment) + 
				"\n       annual_return   = " + std::to_string(annual_return) +
				"\n Payback Period        = " + std::to_string(evaluate_return()) + "\n" ; 
				
	return my_state ;
}

class Simple_Rate_of_Return : public Investment_Return
{
private:
	double investment ;
	double annual_return;
	double estimated_life ;

public:
	Simple_Rate_of_Return( double, double, double );

    double evaluate_return() override;
	
	string toString();
} ; 

Simple_Rate_of_Return::Simple_Rate_of_Return( double investment, double annual_return, double estimated_life )
{
	this->investment      = investment ;
	this->annual_return   = annual_return ;
	this->estimated_life  = estimated_life ;
}
	
double Simple_Rate_of_Return::evaluate_return()
{
	double annual_depreciation = investment / estimated_life ;
	
	double average_investment = investment / 2.0 ;
	
	double simple_ror = (  annual_return - annual_depreciation ) / average_investment ;
	
	return My_Math::round( simple_ror, 2 ) ;
}
	
string Simple_Rate_of_Return::toString()
{
	string my_state;
	
	my_state = "\nGiven: investment      = " + std::to_string(investment) + 
				"\n       annual_return   = " + std::to_string(annual_return) +
				"\n       estimated_life  = " + std::to_string(estimated_life) + 
				"\n Simple Rate of Return = " + std::to_string(evaluate_return()) + "\n" ; 
				
	return my_state ;
}

/*
https://www.investopedia.com/terms/p/present-value-annuity.asp
*/
class Net_Present_Value : public Investment_Return
{
private:
	double investment ;
	double annual_return;
	double estimated_life ;
	double cost_of_capital ;

	double calc_pv_of_annuity() ; // private helper method
		
public:
	Net_Present_Value( double investment, double annual_return, double estimated_life, double cost_of_capital );

	double evaluate_return() override;
	
	string toString();
};

Net_Present_Value::Net_Present_Value( double investment, double annual_return, double estimated_life, double cost_of_capital )
{
	this->investment     = investment ;
	this->annual_return  = annual_return ;
	this->estimated_life = estimated_life ;
	this->cost_of_capital = cost_of_capital ;
}
	
double Net_Present_Value::calc_pv_of_annuity()
{	
	double pv_annuity_factor ;
	
	pv_annuity_factor = ( 1 - ( 1 / pow( 1 + cost_of_capital, estimated_life ) ) ) / cost_of_capital ;

	return annual_return * pv_annuity_factor ;
}

double Net_Present_Value::evaluate_return()
{	
	return My_Math::round( calc_pv_of_annuity() - investment, 2 ) ;
}
	
string Net_Present_Value::toString()
{
	string my_state ;
	
	my_state = "\nGiven: investment      = " + std::to_string(investment) + 
				"\n       annual_return   = " + std::to_string(annual_return) +
				"\n       estimated_life  = " + std::to_string(estimated_life) + 
				"\n       cost_of_capital = " + std::to_string(cost_of_capital) + 
				"\n Net Present Value     = " + std::to_string(evaluate_return()) + "\n" ; 
				
	return my_state ;
}

//====================================== ADDED CODE BELOW ==========================================

class CAGR : public Investment_Return //Compound Annual Growth Rate class
{
private:
    double investment;
    double annual_return;
    double estimated_life;

public:
    CAGR( double investment, double annual_return, double estimated_life );

    double evaluate_return() override;

    string toString();
};  

CAGR::CAGR( double investment, double annual_return, double estimated_life )
{
    this->investment = investment;
    this->annual_return = annual_return;
    this->estimated_life = estimated_life;
}

double CAGR::evaluate_return() //calculates CAGR using formula (EV/BV)^1/n-1
{
    double end_value = ( annual_return * estimated_life ) + investment; //calculating end value by adding (annual return * estimated life) + initial investment 
    double pow_argument1 = end_value / investment; //pow argument variables to make final calculation code cleaner
    double pow_argument2 = 1 / estimated_life;
    double cagr_calc = ( pow( pow_argument1, pow_argument2 ) -1 );

    return cagr_calc;
}

string CAGR::toString()
{
    string my_state;

    my_state = "\nGiven: investment      = " + std::to_string(investment) + 
			    "\n       annual_return   = " + std::to_string(annual_return) +
			    "\n       estimated_life  = " + std::to_string(estimated_life) +
                "\n                CAGR   = " + std::to_string(evaluate_return()) + "\n"; 

    return my_state;
}

class Investment_Evaluator
{
private:
	Investment_Return* inv_return_obj ;

public:

	Investment_Evaluator( Investment_Return* );

	Investment_Evaluator(Investment_Evaluator&) = default; // default copy constructor required

	Investment_Evaluator(Investment_Evaluator&&) = default; // default move constructor required
	
	string toString();
};

Investment_Evaluator::Investment_Evaluator( Investment_Return* inv_return_obj ) 
{
	this->inv_return_obj     = inv_return_obj ;	
}

string Investment_Evaluator::toString()
{
	//cout << "\n\nInvestment_Evaluator::toString() inv_return_obj addr = " << &inv_return_obj << "\n" ;
	//cout << "\n\ninv_return_obj.toString() " << inv_return_obj->toString() << "\n";
	return inv_return_obj->toString() ;
}

    
int main()
{
	double investment       = 1000000.0 ;
	double annual_return    =  100000.0 ;
	double estimated_life   =      15.0 ;
	double cost_of_capital  =      0.10 ;

    double investment2 = 10000.0; //Added these three variable for testing, it's the same as the Excel sheet given
    double annual_return2 = 3000.0;
    double estimated_life2 = 3.0;
	
	Investment_Return* payback_obj = new Pay_Back( investment, annual_return)  ;

	cout << "\n\n======= Pay Back =========\n";
	Investment_Evaluator inv_evaluator_obj_pay( payback_obj );
	cout << "\n\ninv_evaluator_obj_pay address: " << &inv_evaluator_obj_pay ;
	cout << inv_evaluator_obj_pay.toString() ;
	
	Investment_Return* simple_return_obj = new Simple_Rate_of_Return( investment, annual_return, estimated_life ) ;

	Investment_Evaluator inv_evaluator_obj_simp( simple_return_obj );
	
	cout << "\n\n======= Simple Return =========\n";
	cout << "\n\ninv_evaluator_obj_simp address: " << &inv_evaluator_obj_simp ;
	cout << inv_evaluator_obj_simp.toString() ;

	Investment_Return* npv_return_obj = new Net_Present_Value( investment, annual_return, estimated_life, cost_of_capital ) ;
	
	Investment_Evaluator inv_evaluator_obj_npv1(npv_return_obj ) ;
	
	cout << "\n\n======= NPV 1 =========\n";
	cout << "\n\ninv_evaluator_obj_npv1 address: " << &inv_evaluator_obj_npv1 ;
	
	cout << inv_evaluator_obj_npv1.toString() ;

	npv_return_obj = new Net_Present_Value( investment, annual_return, estimated_life, cost_of_capital ) ;
	
	cout << "\n\n======= NPV 2 =========\n";
	cout << npv_return_obj->toString() ;

    //====================================== ADDED CODE BELOW ==========================================

    Investment_Return* cagr_obj = new CAGR (investment2, annual_return2, estimated_life2); //initiating CAGR object

    cout << "\n\n======= Compound Annual Growth Rate =========\n";
    Investment_Evaluator inv_evaluator_obj_cagr( cagr_obj ); //invoking Evaluator for CAGR object
    cout << "\ninv_evaluator_obj_cagr Address: " << &inv_evaluator_obj_cagr << "\n";
    cout << inv_evaluator_obj_cagr.toString(); //displaying CAGR object results

	delete payback_obj ;
	
	delete simple_return_obj ;

	delete npv_return_obj;

    delete cagr_obj; //deleting cagr object

	return 0;
}


