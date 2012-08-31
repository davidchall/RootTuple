//----------------------------------------------------------------------
//                             RootTuple
//  Author:  David Hall
//  Date:    29th August 2012
//  Website: http://roottuple.hepforge.org/
//
//  This declares the RootTuple class.
//
//----------------------------------------------------------------------

#ifndef RootTuple_H
#define RootTuple_H

// Standard C++ libraries
#include <iostream>
#include <string>
#include <vector>

// ROOT libraries
#include <TFile.h>
#include <TTree.h>

class RootTuple{
public:
    // Constructors and destructors
    RootTuple();
    RootTuple(std::string filename, std::string treename);
    ~RootTuple();

    // Public methods
    void Initialise();
    void AddEvent();
    void Write();
    void Close();
    void AddParticle(int barcode, double px, double py, double pz, double e);
    void SetWeight(double weight);

    void SetDoubleBranch(std::string branchname, double *ptr);
    void SetFloatBranch(std::string branchname, float *ptr);
    void SetIntBranch(std::string branchname, int *ptr);
    void SetBoolBranch(std::string branchname, bool *ptr);

private:
    // Private methods
    void DeclareBranches();
    void FillBranches();
    void ClearVectors();

    // ROOT file objects and variables
    TFile *m_file;
    TTree *m_tree;
    std::string m_filename, m_treename;

    // Branch variables
    Double_t m_weight;
    std::vector<Int_t> m_barcode;
    std::vector<Double_t> m_Px, m_Py, m_Pz, m_E;
};

#endif
