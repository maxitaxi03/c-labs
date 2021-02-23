const int MAXROWS=2;
const int MAXCOLS=3;


/*class Matrix{
  private:
  int doubleArray[MAXROWS][MAXCOLS];
   int rows;
   int cols;

  public:
   //Constructor
   Matrix();  //Set rows to MAXROWS and cols to MAXCOLS
	      //Initialize all the values of doubleArray to zero
    
   //Getter Functions
   void printMatrix(); 

   //Setter Functions
   void setMatrix(int [][MAXCOLS]); //set the doubleArray to what is sent
   void addMatrix(int [][MAXCOLS]); //add an array to doubleArray
   void addMatrix(Matrix otherMatrix);

   //No destructor needed
};*/
template <class T>
class Matrix {

    T doubleArray[MAXROWS][MAXCOLS];
    int rows;
    int cols;
public:

    Matrix();
    void printMatrix();
    void setMatrix(T [][MAXCOLS]);
    void addMatrix(T [][MAXCOLS]);
    void addMatrix(Matrix<T> otherMatrix);

};