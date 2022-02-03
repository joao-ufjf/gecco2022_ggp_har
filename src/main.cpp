#include <iostream>
#include "Database.h"
#include "Grammar.h"
#include "No.h"
#include "Configures.h"
#include "Search.h"
#include "MultiSearch.h"
#include "Configures.h"
#include "SimpleParser.h"
#include "SimpleFunctionalEquationsParser.h"
#include "SimpleClassifierParser.h"
#include "AdolfoClassifierParser.h"
#include "../inc/ParserDerivadas.h"
#include "../inc/LeastSquareParser.h"
#include "../inc/LSDerivadasParser.h"
#include "IndividuoBuilder.h"
#include "LeastSquareIndividuoBuilder.h"
#include "../inc/RK4LSDerivadasParser.h"
#include "../inc/RK4LSIndividuoBuilder.h"
#include "Subject.h"
#include "RK4sParser.h"
#include "../inc/RK4AGParser.h"
#include "RK4LSDParser.h"
#include <sstream>
//#include "DifferencialEvolution.h"

#include "../inc/ContinuousAntColonyOptmization.h"

using namespace std;

int func(double sl, double sw, double pl, double pw){
    if(3 >= pl){
        return 0;
    }
    else{
        if(pl >= 5){
            return 2;
        }
        else{
            return 1;
        }
    }
}

#define simpleParser
//#define RK4Parser
int main(int argc, char** argv){
//    cout << "Hello CACO!" << endl;
//
//    conf = new Configures();
//    conf->approach = atoi(argv[5]);
//    conf->output = argv[6];
//    conf->seed = atoi(argv[1]);
//
////	srand(conf->seed);
//	srand(time(NULL));
//
//	conf->MAXDEEP = 4;
//    conf->generations = 100;
//    conf->popSize = 100;
//    conf->elitism = 0.1;
//    conf->crossoverRate = 0.9;
//    conf->mutationRate = 0.9;
//    conf->NUM_THREADS = 1;
//    data = new Database(argv[3]);
//	data->loadGroup(argv[4]);
//	grammar = new Grammar(argv[2]);
//	conf->numTree = data->prediction;
//
////	data->print();
//
////    SimpleParser * parser = new SimpleParser();
////    SimpleParser * parserTest = new SimpleParser();
////    SimpleParser * parserValidation = new SimpleParser();
//    SimpleClassifierParser * parser = new SimpleClassifierParser();
//    SimpleClassifierParser * parserTest = new SimpleClassifierParser();
//    SimpleClassifierParser * parserValidation = new SimpleClassifierParser();
//
//    IndividuoBuilder* individuoBuilder = new SimpleIndividuoBuilder();
//    parser->setDataSet(data->training,data->totalTraining);
//    parserTest->setDataSet(data->test,data->totalTest);
//    parserValidation->setDataSet(data->validation,data->totalValidation);
//
//    Subject* sub = individuoBuilder->generateIndividuo();
//
//    cout << "Função correta f(x, y) = 3x³ - 2y²" << endl;
////    sub->print();
//
//    cout << "Função inserida f(x, y) = 3x³ - 2y²" << endl;
//    sub->print();
//    cout << "mse = " << parser->Evaluate(sub) << endl;
//    cin.get();
//
//
////    19 input/continuous/grammar input/continuous/data input/continuous/groups 0 default_out.txt
////    19 input/gravity/grammar input/gravity/data input/gravity/groups 0 default_out.txt
//
//    ContinuousAntColonyOptmization* caco =
//        new ContinuousAntColonyOptmization();
//
//    caco->Optimize(sub, parser);
//
//
//
//
////    A) Cria no ACO e vai pra GP
////    B) Cria na GP e vai pro ACO
////
////    1) Iniciar a GP
////    2) Periódico na GP
////        a) Best
////        b) Elite
////        c) Pop toda
////    3) No final da GP
////        a) Best
////        b) Elite
////        c) Pop toda
//
//
//    sub->print();
//    cout << "mse pós aco = " << parser->Evaluate(sub) << endl;
//
//    delete caco;
//
//    return 0;








//    cout.precision(10);
    cout << "Hello GP-ufjf!" << endl;
    conf = new Configures();
//    cin.get();
    conf->approach = atoi(argv[5]);
    conf->output = argv[6];
    conf->seed = atoi(argv[1]);
	srand(conf->seed);

//	conf->ffunction = atoi(argv[6]);

	// 0 input/grammar/pvnrt_r.dat input/data/pvnrt_r.dat input/data/pvnrt_r.grp 0

    //set parametros
    conf->MAXDEEP = atoi(argv[7]);

    conf->generations = 100;
    conf->popSize = 500;
    conf->elitism = 0.1;
    conf->crossoverRate = 0.9;
    conf->mutationRate = 0.9;

    conf->NUM_THREADS = 1;

    /// Loading database and grammar
	data = new Database(argv[3]);
	data->loadGroup(argv[4]); // 1000.grp pra 1000, pgDE pra 50
//	grammar = new Grammar("input/grammar/itaDE.dat"); // itaDE.dat para DE, ita.dat para apenas PG
	grammar = new Grammar(argv[2]); // itaDE.dat para DE, ita.dat para apenas PG
//	cin.get();
#define normal

//    int k = 0;
//
//    for(int i = 0; i < data->totalTraining; i++){
//        cout << i << " ";
//        for(int j = 0; j < data->variables + data->prediction; j++)
//            cout << data->training[i][j] << " ";
//        cout << endl;
//        k++;
//    }
//
//    cin.get();
//
//    for(int i = 0; i < data->totalTest; i++){
//        cout << i << " ";
//        for(int j = 0; j < data->variables + data->prediction; j++)
//            cout << data->test[i][j] << " ";
//        cout << endl;
//    }

//    data->print();

//    cin.get();

#ifdef normal

    conf->numTree = data->prediction; // seta o numero de variaveis a serem preditas. dependente do problema a ser tratado
    cout << "NumTree: " << conf->numTree << endl;
//    grammar->print();
//    cin.get();
//    data->print();
    double** dados_treino = data->values;
    //cout << "total training " << data->totalTraining << " total test " << data->totalTest << " total validation "<< data->totalValidation << endl;

     IndividuoBuilder * individuoBuilder = NULL;

    /// Setting parser

    #ifdef simpleParser
//    SimpleParser * parser = new SimpleParser();
//    SimpleParser * parserTest = new SimpleParser();
//    SimpleParser * parserValidation = new SimpleParser();
//    SimpleFunctionalEquationsParser * parser = new SimpleFunctionalEquationsParser();
//    SimpleFunctionalEquationsParser * parserTest = new SimpleFunctionalEquationsParser();
//    SimpleFunctionalEquationsParser * parserValidation = new SimpleFunctionalEquationsParser();
        SimpleClassifierParser * parser = new SimpleClassifierParser();
        SimpleClassifierParser * parserTest = new SimpleClassifierParser();
        SimpleClassifierParser * parserValidation = new SimpleClassifierParser();
//        AdolfoClassifierParser * parser = new AdolfoClassifierParser();
//        AdolfoClassifierParser * parserTest = new AdolfoClassifierParser();
//        AdolfoClassifierParser * parserValidation = new AdolfoClassifierParser();
        individuoBuilder = new SimpleIndividuoBuilder();
    #endif

//    cout << "Seed : " << seed << endl;
    cout << "TotalTrain : " << data->totalTraining << endl;
    cout << "TotalTest : " << data->totalTest << endl;
    cout << "TotalValidation : " << data->totalValidation << endl;


    parser->setDataSet(data->training,data->totalTraining);
    parserTest->setDataSet(data->test,data->totalTest);
    parserValidation->setDataSet(data->validation,data->totalValidation);
//    cin.get();


//    parserTest->printData();
//    cin.get();

    //DifferencialEvolution* de = new DifferencialEvolution();
//
    //Subject* sub = individuoBuilder->generateIndividuo();
    //sub->print();
    //cin.get();
    //de->Optimize(sub, parser);
//    sub->print();
//    delete sub;
//
//    sub = individuoBuilder->generateIndividuo();
//    sub->print();
//    de->Optimize(sub, parser);
//    sub->print();

    /*** CAUTION === IF A PARSER RECIEVES AN ELEMENT THAT IT CAN'T RECOGNIZE IT'LL TREAT LIKE 1 ***/


    grammar->addConstant(-1.00);
    grammar->addConstant(-0.75);
    grammar->addConstant(-0.50);
    grammar->addConstant(-0.25);
    grammar->addConstant(+0.00);
    grammar->addConstant(+0.25);
    grammar->addConstant(+0.50);
    grammar->addConstant(+0.75);
    grammar->addConstant(+1.00);

//    grammar->print();
//    cin.get();

//    data->print();

    Search* s = new Search(parser, NULL, individuoBuilder);
//    MultiSearch* s = new MultiSearch(parser, NULL, individuoBuilder);
    s->setParserTest(parserTest);
    s->setParserValidation(parserValidation);
    s->stepByStep = false;
    //conf->wall_timer = omp_get_wtime();
    s->evolve(); // Execucao para o DE
//    s->evolvePG();
//
//    cout <<  "\n TotalLS : " << conf->totalLS << "\nDeu ruim LS : "<< conf->deuRuimOLS <<endl;
//    cout << "% que deu Ruim : "<< (100.0/((double)conf->totalLS+conf->deuRuimOLS))*conf->deuRuimOLS << "%" << endl;
#endif

    return 0;
}
