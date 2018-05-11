//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
// $Id: HistoManager.cc 72242 2013-07-12 08:44:19Z gcosmo $
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include <CLHEP/Units/SystemOfUnits.h>
#include <sstream>

#include "HistoManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

HistoManager::HistoManager()
  :fFileName("phaseiiv1")
{
  Book();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

HistoManager::~HistoManager()
{
  delete G4AnalysisManager::Instance();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void HistoManager::Book()
{
  // Create or get analysis manager
  // The choice of analysis technology is done via selection of a namespace
  // in HistoManager.hh
  // Creating a tree container to handle histograms and ntuples.
  // This tree is associated to an output file.
  //
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager->SetFileName(fFileName);
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetActivation(true);   //enable inactivation of histograms

  
  // Define histograms start values
  // const G4int kNbofStrips = 1016;
  const G4int kMaxHisto = 123;

  const G4String id[] = { "0", "1", "2", "3" , "4", "5", "6", "7", "8", "9" , "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "90", "91", "92", "93", "94", "95", "96", "97", "98", "99", "100", "101", "102", "103", "104", "105", "106", "107", "108", "109", "110", "111", "112", "113", "114", "115", "116", "117", "118", "119", "120", "121", "122" };
  const G4String title[] =
                { "dummy",                                                       //0
                  "continuous energy loss along primary track for Detector 1",   //1
                  "continuous energy loss along primary track for Detector 2",   //2
                  "energy from secondaries for Detector 1",                      //3
                  "energy from secondaries for Detector 2",                      //4
                  "energy from tertiaries for Detector 1",                       //5
                  "energy from tertiaries for Detector 2",                       //6
                  "total energy lost by primary track for Detector 1",           //7
                  "total energy lost by primary track for Detector 2",           //8
                  "energy spectrum of secondary e-+ for Detector 1",             //9
                  "energy spectrum of secondary e-+ for Detector 2",             //10
                  "energy spectrum of secondary gamma for Detector 1",           //11
                  "energy spectrum of secondary gamma for Detector 2",           //12
                  "energy spectrum of tertiary e-+ for Detector 1",              //13
                  "energy spectrum of tertiary e-+ for Detector 2",              //14
                  "energy spectrum of tertiary gamma for Detector 1",            //15
                  "energy spectrum of tertiary gamma for Detector 2",            //16
                  "step size for primary",                                       //17
                  "step size for secondaries",                                   //18
                  "step size for tertiaries",                                    //19
                  "step size for secondaries created in detectors",              //20
                  "x-polarization of secondaries",                               //21
                  "y-polarization of secondaries",                               //22
                  "z-polarization of secondaries",                               //23
                  "x-polarization of tertiaries",                                //24
                  "y-polarization of tertiaries",                                //25
                  "z-polarization of tertiaries",                                //26
                  "track length for primary",                                    //27
                  "total track length of secondaries",                           //28
                  "total track length of tertiaries",                            //29
                  "total track length of secondaries created in detectors",      //30
                  "track length of secondaries created in detectors",            //31
                  "number of positrons created in Detector 1",       		 //32
                  "number of positrons created in Detector 2",       		 //33
                  "number of electrons created in Detector 1",       		 //34
                  "number of electrons created in Detector 2",       		 //35
                  "number of pi+ created in Detector 1",             		 //36
                  "number of pi+ created in Detector 2",             		 //37
                  "number of pi- created in Detector 1",              		 //38
                  "number of pi- created in Detector 2",             		 //39
                  "number of mu+ created in Detector 1",             		 //40
                  "number of mu+ created in Detector 2",             		 //41
                  "number of mu- created in Detector 1",             		 //42
                  "number of mu- created in Detector 2",              		 //43
		  "number of delta e- created in Detector 1 that have reached Detector 2", //44
		  "number of delta e- created in Detector 2 that have reached Detector 1", //45
                  "number of e+ created before Detector 1",               	 //46
                  "number of e- created before Detector 1",               	 //47
		  "number of e+ created between Detector 1 and Detector 2", 	 //48
		  "number of e- created between Detector 1 and Detector 2", 	 //49
                  "number of e+ created after Detector 2",               	 //50
                  "number of e- created after Detector 2",                	 //51
                  "continuous energy loss along primary track for strip 505 a Detector 1",   //52
                  "continuous energy loss along primary track for strip 506 a Detector 1",   //53
                  "continuous energy loss along primary track for strip 507 a Detector 1",   //54
                  "continuous energy loss along primary track for strip 508 a Detector 1",   //55
                  "continuous energy loss along primary track for strip 509 a Detector 1",   //56
                  "continuous energy loss along primary track for strip 510 a Detector 1",   //57
                  "continuous energy loss along primary track for strip 511 a Detector 1",   //58
                  "continuous energy loss along primary track for strip 512 a Detector 1",   //59
                  "continuous energy loss along primary track for strip 505 b Detector 1",   //60
                  "continuous energy loss along primary track for strip 506 b Detector 1",   //61
                  "continuous energy loss along primary track for strip 507 b Detector 1",   //62
                  "continuous energy loss along primary track for strip 508 b Detector 1",   //63
                  "continuous energy loss along primary track for strip 509 b Detector 1",   //64
                  "continuous energy loss along primary track for strip 510 b Detector 1",   //65
                  "continuous energy loss along primary track for strip 511 b Detector 1",   //66
                  "continuous energy loss along primary track for strip 512 b Detector 1",   //67
                  "continuous energy loss along primary track for strip 505 a Detector 2",   //68
                  "continuous energy loss along primary track for strip 506 a Detector 2",   //69
                  "continuous energy loss along primary track for strip 507 a Detector 2",   //70
                  "continuous energy loss along primary track for strip 508 a Detector 2",   //71
                  "continuous energy loss along primary track for strip 509 a Detector 2",   //72
                  "continuous energy loss along primary track for strip 510 a Detector 2",   //73
                  "continuous energy loss along primary track for strip 511 a Detector 2",   //74
                  "continuous energy loss along primary track for strip 512 a Detector 2",   //75
                  "continuous energy loss along primary track for strip 505 b Detector 2",   //76
                  "continuous energy loss along primary track for strip 506 b Detector 2",   //77
                  "continuous energy loss along primary track for strip 507 b Detector 2",   //78
                  "continuous energy loss along primary track for strip 508 b Detector 2",   //79
                  "continuous energy loss along primary track for strip 509 b Detector 2",   //80
                  "continuous energy loss along primary track for strip 510 b Detector 2",   //81
                  "continuous energy loss along primary track for strip 511 b Detector 2",   //82
                  "continuous energy loss along primary track for strip 512 b Detector 2",   //83
                  "number of electrons created in strip 505 a Detector 1",   //84
                  "number of electrons created in strip 506 a Detector 1",   //85
                  "number of electrons created in strip 507 a Detector 1",   //86
                  "number of electrons created in strip 508 a Detector 1",   //87
                  "number of electrons created in strip 509 a Detector 1",   //88
                  "number of electrons created in strip 510 a Detector 1",   //89
                  "number of electrons created in strip 511 a Detector 1",   //90
                  "number of electrons created in strip 512 a Detector 1",   //91
                  "number of electrons created in strip 505 b Detector 1",   //92
                  "number of electrons created in strip 506 b Detector 1",   //93
                  "number of electrons created in strip 507 b Detector 1",   //94
                  "number of electrons created in strip 508 b Detector 1",   //95
                  "number of electrons created in strip 509 b Detector 1",   //96
                  "number of electrons created in strip 510 b Detector 1",   //97
                  "number of electrons created in strip 511 b Detector 1",   //98
                  "number of electrons created in strip 512 b Detector 1",   //99
                  "number of electrons created in strip 505 a Detector 2",   //100
                  "number of electrons created in strip 506 a Detector 2",   //101
                  "number of electrons created in strip 507 a Detector 2",   //102
                  "number of electrons created in strip 508 a Detector 2",   //103
                  "number of electrons created in strip 509 a Detector 2",   //104
                  "number of electrons created in strip 510 a Detector 2",   //105
                  "number of electrons created in strip 511 a Detector 2",   //106
                  "number of electrons created in strip 512 a Detector 2",   //107
                  "number of electrons created in strip 505 b Detector 2",   //108
                  "number of electrons created in strip 506 b Detector 2",   //109
                  "number of electrons created in strip 507 b Detector 2",   //110
                  "number of electrons created in strip 508 b Detector 2",   //111
                  "number of electrons created in strip 509 b Detector 2",   //112
                  "number of electrons created in strip 510 b Detector 2",   //113
                  "number of electrons created in strip 511 b Detector 2",   //114
                  "number of electrons created in strip 512 b Detector 2",   //115
                  "deflection angle of primary particle (rad)",              //116
                  "distance between midpoint of primary inside Detector 1 and AD",   //117
                  "distance between midpoint of primary inside Detector 2 and AD",   //118
                  "2S first-plane residuals in x-direction",   //119
                  "2S first-plane residuals in y-direction",   //120
                  "2S second-plane residuals in x-direction",   //121
                  "2S second-plane residuals in y-direction"    //122
                  //"midpoint of primary particle inside Pixel Detector 1",
                  //"midpoint of primary particle inside Strip Detector 1",
                  //"midpoint of primary particle inside Strip Detector 2",
                  //"midpoint of primary particle inside Pixel Detector 2"
                 };
            
  // Default values (to be reset via /analysis/h1/set command)               
  G4int nbins = 100;
  G4double vmin = -1.5;
  G4double vmax = 100.;

  // Create all histograms as inactivated 
  // as we have not yet set nbins, vmin, vmax
  for (G4int k=0; k<kMaxHisto; k++) {
    G4int ih = analysisManager->CreateH1(id[k], title[k], nbins, vmin, vmax);
    analysisManager->SetH1Activation(ih, false);
  }

  //Create H3 histograms
  //G4int ih1 = analysisManager->CreateH3("85", "midpoint of primary particle inside Pixel Detector 1", 10000, -2*cm, 2*cm, 10000, -2*cm, 2*cm, 10000, -2*cm, 2*cm, "cm", "cm", "cm");
  //analysisManager->SetH3Activation(ih1, false);
  //G4int ih2 = analysisManager->CreateH3("86", "midpoint of primary particle inside Strip Detector 1", 1000, -2*mm, 2*mm, 1000, -2*mm, 2*mm, 1000, -2*mm, 2*mm, "mm", "mm", "mm");
  //analysisManager->SetH3Activation(ih2, false);
  //G4int ih3 = analysisManager->CreateH3("87", "midpoint of primary particle inside Strip Detector 2", 1000, -2*mm, 2*mm, 1000, -2*mm, 2*mm, 1000, -2*mm, 2*mm, "mm", "mm", "mm");
  //analysisManager->SetH3Activation(ih3, false);
  //G4int ih4 = analysisManager->CreateH3("88", "midpoint of primary particle inside Pixel Detector 2", 10000, -2*cm, 2*cm, 10000, -2*cm, 2*cm, 10000, -2*cm, 2*cm, "cm", "cm", "cm");
  //analysisManager->SetH3Activation(ih4, false);

  // nTuples, column l: 1 to 1016 correspond to Detector 1, 2 to 2032 correspond to Detector 2
  //
  analysisManager->SetNtupleDirectoryName("ntuple");
  analysisManager->SetFirstNtupleId(1);       
  analysisManager->CreateNtuple("1", "Primary Particle Tuple 1");
  for (G4int l=0; l<1017; l++) {
     std::ostringstream os1;
     os1 <<"EdepStripDetector1a_" << l;
     analysisManager->CreateNtupleDColumn(os1.str());          //
  }
  for (G4int m1=0; m1<1017; m1++) {
     std::ostringstream os2;
     os2 <<"EdepStripDetector1b_" << m1;
     analysisManager->CreateNtupleDColumn(os2.str());          //
  }
  for (G4int ma=0; ma<1017; ma++) {
     std::ostringstream os3;
     os3 <<"EdepStripDetector2a_" << ma;
     analysisManager->CreateNtupleDColumn(os3.str());          //
  }
  for (G4int mb=0; mb<1017; mb++) {
     std::ostringstream os4;
     os4 <<"EdepStripDetector2b_" << mb;
     analysisManager->CreateNtupleDColumn(os4.str());          //
  }
  //for (G4int n=0; n<1017; n++) {
     //std::ostringstream os3;
     //os3 <<"NbElectronsStripDetector1_" << n;
     //analysisManager->CreateNtupleDColumn(os3.str());          //
  //}
  //for (G4int o=0; o<1017; o++) {
     //std::ostringstream os4;
     //os4 <<"NbElectronsStripDetector2_" << o;
     //analysisManager->CreateNtupleDColumn(os4.str());          //
  //}
  analysisManager->FinishNtuple();
  
  //analysisManager->SetNtupleActivation(false);  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
