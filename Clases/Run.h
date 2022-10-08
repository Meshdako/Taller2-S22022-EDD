#ifndef RUN_H
#define RUN_H

class RUN
{
    private:
        long runSdv;
        char dv;
    public:
        //Constructor
        RUN();
        RUN(long, char);

        //Sets
        void setRun(long x){runSdv = x;}
        void setDv(char x){dv = x;}

        //Gets
        long getRun(){return runSdv;}
        char getDv(){return dv;}

        void verRun();
};

#endif //RUN_H