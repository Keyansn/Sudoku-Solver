#include <iostream>
#include <vector> //because using vectors
#include <fstream> //because we are using files
#include <cstdlib> //to do the exit failure
using namespace std;

struct puzzle
{
        int newknown;
        int known;
        int value;
        int valuenot[10];
};

/*
void checkzero(puzzle sudoku[][9]){

    for (int y=0; y<9; y++){

        	   for (int x=0; x<9; x++){

        		   if (sudoku[x][y].value != 0){
        			   sudoku[x][y].known = 1;
        		   }

        		   else{
        			   sudoku[x][y].known = 0;
        		   }

        	   }}

}*/

int main()
{
puzzle sudoku [9][9];
int* pointer;
int ptrval;
int* pointerother;
int ptrvalother;
int xsqr;
int ysqr;
int count=0;
bool readloop = true;

//////////////////////////////////////////////////////////////////////////////


        ifstream infile;

        infile.open("sudoku.txt");

        if( !infile.is_open())
        {
                cout << "could not open file" << endl;
                exit(EXIT_FAILURE);
        }

       for (int y=0; y<9; y++){
    	   for (int x=0; x<9; x++){
    	   infile >> sudoku[x][y].value;
       }}


        infile.close();



//////////////////////////////////////////////////////////////////////////////
       for (int y=0; y<9; y++){

           	   for (int x=0; x<9; x++){
           		   if (sudoku[x][y].value != 0){
           			sudoku[x][y].known = 1;
           		   }

           		   else{
           			   sudoku[x][y].known = 0;
           		   }

           	   }}

       //////////////////////////////////////////////////////////////////////////////
                      for (int y=0; y<9; y++){

                          for (int x=0; x<9; x++){

                              for (int v=0; v<9; v++){

                                 			   sudoku[x][y].valuenot[v] = 0;

                                 		   }}}

//       void checkzero (sudoku);




//////////////////////////////////////////////////////////////////////////////

while (readloop == true){

    for (int y=0; y<9; y++){

        	   for (int x=0; x<9; x++){
        		   if (sudoku[x][y].value != 0){
        			sudoku[x][y].known = 1;
        		   }

        		   else{
        			   sudoku[x][y].known = 0;
        		   }

        	   }}

       for (int y=0; y<9; y++){

           for (int x=0; x<9; x++){

        	   for (int z=0; z<9; z++){

           		pointer = &sudoku[x][y].value;
           		ptrval = *pointer;
           		pointerother = &sudoku[x][z].value;
           		ptrvalother = *pointerother;

           		if ((ptrval == 0)&&(y!=z)&&(ptrvalother!=0)){
           			sudoku[x][y].valuenot[ptrvalother] = 1;

           		}
       }
           }

       }
//////////////////////////////////////////////////////////////////////////////

       for (int y=0; y<9; y++){

          for (int x=0; x<9; x++){

              for (int z=0; z<9; z++){

                 		pointer = &sudoku[x][y].value;
                 		ptrval = *pointer;

                 		pointerother = &sudoku[z][y].value;
                 		ptrvalother = *pointerother;

                 		if ((ptrval == 0)&&(x!=z)&&(ptrvalother!=0)){
                 			sudoku[x][y].valuenot[ptrvalother] = 1;
                 		}
             }
                 }

             }

//////////////////////////////////////////////////////////////////////////////

      for (int x=0; x<9; x++){

          for (int y=0; y<9; y++){

            	  if (x<3){ xsqr = 0;}
            	  else if (x>5){ xsqr = 6;}
            	  else {xsqr = 3;}

            	  if (y<3){ ysqr = 0;}
            	  else if (y>5){ ysqr = 6;}
            	  else {ysqr = 3;}

            //	  cout << "y = " << y << endl << "x = " << x << endl << "xsqr = " << xsqr << endl
            //		  << "ysqr = " << ysqr << endl << endl;

            	  for (int a=0; a<3; a++){
            		  for (int b=0; b<3; b++){

                    	  pointer = &sudoku[x][y].value;
                    	  ptrval = *pointer;
                    	  pointerother = &sudoku[(xsqr+a)][(ysqr+b)].value;
                    	  ptrvalother = *pointerother;

                    	  if((ptrval == 0)&&(ptrvalother!=0)){
                    		  sudoku[x][y].valuenot[ptrvalother] = 1;

                    	  }

            		  }
            	  }


              }}

//////////////////////////////////////////////////////////////////////////////


    for (int a=0; a<9; a++){

           	   for (int b=0; b<9; b++){
           		   	   cout << sudoku[b][a].value << " ";
           		   	   if (b==8){
           		   		cout << endl;
           		   	   }
           	   }
        }

    cout << endl;

//////////////////////////////////////////////////////////////////////////////

    for (int a=0; a<9; a++){

               	   for (int b=0; b<9; b++){
               		   	   cout << sudoku[b][a].known << " ";
               		   	   if (b==8){
               		   		cout << endl;
               		   	   }
               	   }
            }
    cout << endl;

/////////////////////////////////////////////////////////////////////////////
/*
    for (int a=0; a<9; a++){
       for (int b=0; b<9; b++){
            if (sudoku[b][a].known == 1){
            	for (int c=0; c<10; c++){
            		sudoku[b][a].valuenot[c] = 1;
            	}
               		   	   }

               	   }
            }

    cout << endl;
*/
//////////////////////////////////////////////////////////////////////////////



    for (int a=0; a<9; a++){
    		for (int b=0; b<9; b++){
                  		   for (int c=0; c<10; c++){

                  			if (c == 0){
                  				cout << "(";
                  			}

                  		   if ((sudoku[b][a].valuenot[c] != 1)&&(c!=0)&&(sudoku[b][a].known != 1)){
                  		   	   cout << c << " ";
                  		   	   }
                  		   if ((sudoku[b][a].known == 1)&&(c==5)){
                  			   cout << "known";
                  		   }

                  		   if (c == 9){
                  			   cout << ")";
                  		   }
                  	   }

                  		 if (b==8){
                  		  cout << endl;
                  		 	 	 	 	 }

               }
    }

    //////////////////////////////////////////////////////////////////////////////



    for (int y=0; y<9; y++){

       for (int x=0; x<9; x++){

           for (int z=1; z<10; z++){

        	  if (sudoku[x][y].valuenot[z]){
        		  count++;

        	  }}
           	   if (count == 8){
           		for (int f=1; f<10; f++){
           			if (sudoku[x][y].valuenot[f] == 0){

           				sudoku[x][y].valuenot[0] = 1;
           				sudoku[x][y].valuenot[f] = 1;
           				sudoku[x][y].value = f;
           				sudoku[x][y].newknown = 1;
           				cout << "changed" << endl;
           			}
           		}
        	  cout << "found" << endl;
           }
           count = 0;
       	   }
           }
////////////////////////////////////////////////////////////////////////////////////
   count = 0;
    for (int y=0; y<9; y++){
    	for (int x=0; x<9; x++){
     		pointer = &sudoku[x][y].known;
     		ptrval = *pointer;

     		pointerother = &sudoku[x][y].newknown;
     		ptrvalother = *pointerother;
    	   if (ptrval != ptrvalother){
    		   count++;

    	   }
       }}

    if (count == 0){
    	readloop = false;
    	cout << "end" << endl;
    }

    else {
    	cout << "loop" << count << endl;
    }

    for (int a=0; a<9; a++){
         for (int b=0; b<9; b++){
             sudoku[b][a].newknown = sudoku[b][a].known;

               	   }
            }


} //ends readloop
    ////////////////////////////////////////////////////////////////////////////////////

    for (int a=0; a<9; a++){
    		for (int b=0; b<9; b++){
                  		   for (int c=0; c<10; c++){

                  			if (c == 0){
                  				cout << "(";
                  			}

                  		   if ((sudoku[b][a].valuenot[c] != 1)&&(c!=0)){
                  		   	   cout << c << " ";
                  		   	   }
                  		   if ((sudoku[b][a].valuenot[0] == 1)&&(c==5)){
                  			   cout << "known";
                  		   }

                  		   if (c == 9){
                  			   cout << ")";
                  		   }
                  	   }

                  		 if (b==8){
                  		  cout << endl;
                  		 	 	 	 	 }

               }
    }
    //////////////////////////////////////////////////////////////////////////////

    cout << "known" << endl;

    for (int a=0; a<9; a++){

               	   for (int b=0; b<9; b++){
               		   	   cout << sudoku[b][a].known << " ";
               		   	   if (b==8){
               		   		cout << endl;
               		   	   }
               	   }
            }

    cout << "new known" << endl;

    for (int a=0; a<9; a++){

               	   for (int b=0; b<9; b++){
               		   	   cout << sudoku[b][a].newknown << " ";
               		   	   if (b==8){
               		   		cout << endl;
               		   	   }
               	   }
            }

    cout << endl;

    for (int a=0; a<9; a++){

           	   for (int b=0; b<9; b++){
           		   	   cout << sudoku[b][a].value << " ";
           		   	   if (b==8){
           		   		cout << endl;
           		   	   }
           	   }
        }




        return 0;

}



