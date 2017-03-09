#include "TTree.h"
#include "TFile.h"
#include "TStopwatch.h"
#include "TSystem.h"
#include <cstdlib>
#include <cmath>

// modifié pour utliser que le Tight2012


void prepareForSoup() {
	using namespace std;

TChain * ch = new TChain("tpTree/fitter_tree");
TFileCollection fc("test","","myfileList_test.txt");
ch->AddFileInfoList(fc.GetList());

//    TTree *tIn  = (TTree *) gFile->Get("tpTree/fitter_tree");
    TTree *tIn = ch;
    Float_t pt, abseta, pair_probeMultiplicity, tag_eta, tag_nVertices, mass;
    Int_t event;
    Int_t tkHighPt, tag_tkHighPt, tag_Mu17_IsoTrkVVL, Mu17_IsoTrkVVL;
    Float_t combRelIsoPF04dBeta, tag_combRelIsoPF04dBeta, tkIso, tag_tkIso;
    Int_t DoubleIsoMu17Mu8dZ_Mu17leg, DoubleIsoMu17Mu8_IsoMu17leg, DoubleIsoMu17Mu8_Mu17leg,  DoubleIsoMu17Mu8_IsoMu8leg, DoubleIsoMu17Mu8_Mu8leg, DoubleIsoMu17TkMu8dZ_Mu17, DoubleIsoMu17TkMu8_IsoMu17leg, DoubleIsoMu17TkMu8_Mu17leg, DoubleIsoMu17TkMu8_IsoMu8leg, DoubleIsoMu17TkMu8_TkMu8leg;
    Int_t tag_DoubleIsoMu17Mu8dZ_Mu17leg, tag_DoubleIsoMu17Mu8_IsoMu17leg, tag_DoubleIsoMu17Mu8_Mu17leg,  tag_DoubleIsoMu17Mu8_IsoMu8leg, tag_DoubleIsoMu17Mu8_Mu8leg, tag_DoubleIsoMu17TkMu8dZ_Mu17, tag_DoubleIsoMu17TkMu8_IsoMu17leg, tag_DoubleIsoMu17TkMu8_Mu17leg, tag_DoubleIsoMu17TkMu8_IsoMu8leg, tag_DoubleIsoMu17TkMu8_TkMu8leg;
    
    Int_t IsoMu22, tag_IsoMu22;
    Int_t IsoTkMu22, tag_IsoTkMu22;
    Int_t IsoMu24, tag_IsoMu24;
    Int_t IsoTkMu24, tag_IsoTkMu24;

    tIn->SetBranchAddress("pt", &pt);
    tIn->SetBranchAddress("abseta", &abseta);
    tIn->SetBranchAddress("tag_eta", &tag_eta);
    tIn->SetBranchAddress("mass", &mass);
    tIn->SetBranchAddress("pair_probeMultiplicity", &pair_probeMultiplicity);
    tIn->SetBranchAddress("event", &event);
    tIn->SetBranchAddress("tkHighPt", &tkHighPt);
    tIn->SetBranchAddress("tag_tkHighPt", &tag_tkHighPt);
    tIn->SetBranchAddress("tag_Mu17_IsoTrkVVL", &tag_Mu17_IsoTrkVVL);
    tIn->SetBranchAddress("Mu17_IsoTrkVVL", &Mu17_IsoTrkVVL);
    tIn->SetBranchAddress("tag_nVertices", &tag_nVertices);
    tIn->SetBranchAddress("tag_combRelIsoPF04dBeta", &tag_combRelIsoPF04dBeta);
    tIn->SetBranchAddress("combRelIsoPF04dBeta", &combRelIsoPF04dBeta);
    tIn->SetBranchAddress("tag_tkIso", &tag_tkIso);
    tIn->SetBranchAddress("tkIso", &tkIso);
    
    tIn->SetBranchAddress("IsoMu22", &IsoMu22);
    tIn->SetBranchAddress("tag_IsoMu22", &tag_IsoMu22);
    tIn->SetBranchAddress("IsoTkMu22", &IsoTkMu22);
    tIn->SetBranchAddress("tag_IsoMu22", &tag_IsoMu22);
    tIn->SetBranchAddress("IsoMu24", &IsoMu24);
    tIn->SetBranchAddress("tag_IsoMu24", &tag_IsoMu24);
    tIn->SetBranchAddress("IsoTkMu24", &IsoTkMu24);
    tIn->SetBranchAddress("tag_IsoMu24", &tag_IsoMu24);

    tIn->SetBranchAddress("DoubleIsoMu17Mu8dZ_Mu17leg", &DoubleIsoMu17Mu8dZ_Mu17leg);
    tIn->SetBranchAddress("DoubleIsoMu17Mu8_IsoMu17leg", &DoubleIsoMu17Mu8_IsoMu17leg);
    tIn->SetBranchAddress("DoubleIsoMu17Mu8_Mu17leg", &DoubleIsoMu17Mu8_Mu17leg);
    tIn->SetBranchAddress("DoubleIsoMu17Mu8_IsoMu8leg", &DoubleIsoMu17Mu8_IsoMu8leg);
    tIn->SetBranchAddress("DoubleIsoMu17Mu8_Mu8leg", &DoubleIsoMu17Mu8_Mu8leg);
    tIn->SetBranchAddress("DoubleIsoMu17TkMu8dZ_Mu17", &DoubleIsoMu17TkMu8dZ_Mu17);
    tIn->SetBranchAddress("DoubleIsoMu17TkMu8_IsoMu17leg", &DoubleIsoMu17TkMu8_IsoMu17leg);
    tIn->SetBranchAddress("DoubleIsoMu17TkMu8_Mu17leg", &DoubleIsoMu17TkMu8_Mu17leg);
    tIn->SetBranchAddress("DoubleIsoMu17TkMu8_IsoMu8leg", &DoubleIsoMu17TkMu8_IsoMu8leg);
    tIn->SetBranchAddress("DoubleIsoMu17TkMu8_TkMu8leg", &DoubleIsoMu17TkMu8_TkMu8leg);

    tIn->SetBranchAddress("tag_DoubleIsoMu17Mu8dZ_Mu17leg", &tag_DoubleIsoMu17Mu8dZ_Mu17leg);
    tIn->SetBranchAddress("tag_DoubleIsoMu17Mu8_IsoMu17leg", &tag_DoubleIsoMu17Mu8_IsoMu17leg);
    tIn->SetBranchAddress("tag_DoubleIsoMu17Mu8_Mu17leg", &tag_DoubleIsoMu17Mu8_Mu17leg);
    tIn->SetBranchAddress("tag_DoubleIsoMu17Mu8_IsoMu8leg", &tag_DoubleIsoMu17Mu8_IsoMu8leg);
    tIn->SetBranchAddress("tag_DoubleIsoMu17Mu8_Mu8leg", &tag_DoubleIsoMu17Mu8_Mu8leg);
    tIn->SetBranchAddress("tag_DoubleIsoMu17TkMu8dZ_Mu17", &tag_DoubleIsoMu17TkMu8dZ_Mu17);
    tIn->SetBranchAddress("tag_DoubleIsoMu17TkMu8_IsoMu17leg", &tag_DoubleIsoMu17TkMu8_IsoMu17leg);
    tIn->SetBranchAddress("tag_DoubleIsoMu17TkMu8_Mu17leg", &tag_DoubleIsoMu17TkMu8_Mu17leg);
    tIn->SetBranchAddress("tag_DoubleIsoMu17TkMu8_IsoMu8leg", &tag_DoubleIsoMu17TkMu8_IsoMu8leg);
    tIn->SetBranchAddress("tag_DoubleIsoMu17TkMu8_TkMu8leg", &tag_DoubleIsoMu17TkMu8_TkMu8leg);

	

    TFile *fOut = new TFile("/afs/cern.ch/work/s/skeshri/Analysis/Moriond2017/Muon_Iso_Trig/Trigger/Muon_trig/CMSSW_8_0_25/src/doubleMuonInRunII/OutRoot/soup_tree.root", "RECREATE");
    //TFile *fOut = new TFile("/afs/cern.ch/work/h/hbrun/pogTnPr7/TnP_Data_"+NameFile+".root", "RECREATE");
    fOut->mkdir("tpTree")->cd();
    TTree *tOut = tIn->CloneTree(0);
    Int_t passIsoCut, passORDoubleMuons, passORallPaths;
  //  Int_t passORdiMu, passORdiMuNodZ, passMu17Mu8, passMu17Mu8NoDz, passMu17TkMu8, passMu17TkMu8NoDz,passLoose;
    tOut->Branch("passIsoCut", &passIsoCut, "passIsoCut/I");
    tOut->Branch("passORDoubleMuons", &passORDoubleMuons, "passORDoubleMuons/I");
    tOut->Branch("passORallPaths", &passORallPaths, "passORallPaths/I");
    //tOut->Branch("tag_abseta", &tag_abseta, "tag_abseta/F");

    
  

    int step = tIn->GetEntries()/1000;
    double evDenom = 100.0/double(tIn->GetEntries());
    TStopwatch timer; timer.Start();
	int theEvent = 0;
    for (int i = 0, n = tIn->GetEntries(); i < n; ++i) {
	//for (int i = 0, n = 1000; i < n; ++i) {
        tIn->GetEntry(i);
        //if (i > 20000) break;
        if ((i+1) % step == 0) { 
            double totalTime = timer.RealTime()/60.; timer.Continue();
            double fraction = double(i+1)/double(n+1), remaining = totalTime*(1-fraction)/fraction;
            printf("Done %9d/%9d   %5.1f%%   (elapsed %5.1f min, remaining %5.1f min)\n", i, n, i*evDenom, totalTime, remaining); 
            fflush(stdout);
        }
        if (!(tag_Mu17_IsoTrkVVL||Mu17_IsoTrkVVL)) continue;
        if (!(tag_tkHighPt)) continue;
        if (!(tag_combRelIsoPF04dBeta<0.15 && tag_tkIso<0.1)) continue;
        if (!(pair_probeMultiplicity==1)) continue;
        if (!(tkHighPt)) continue;
        if (!(combRelIsoPF04dBeta<0.15 && tkIso<0.1)) continue;
        passORDoubleMuons = ((tag_DoubleIsoMu17Mu8dZ_Mu17leg && DoubleIsoMu17Mu8_IsoMu8leg)||(DoubleIsoMu17Mu8dZ_Mu17leg && tag_DoubleIsoMu17Mu8_IsoMu8leg))||((tag_DoubleIsoMu17TkMu8dZ_Mu17 && DoubleIsoMu17TkMu8_IsoMu8leg)||(DoubleIsoMu17TkMu8dZ_Mu17 && tag_DoubleIsoMu17TkMu8_IsoMu8leg))||((tag_DoubleIsoMu17TkMu8_Mu17leg && DoubleIsoMu17TkMu8_TkMu8leg)||(DoubleIsoMu17TkMu8_Mu17leg && tag_DoubleIsoMu17TkMu8_TkMu8leg))||((tag_DoubleIsoMu17Mu8_IsoMu17leg && DoubleIsoMu17Mu8_IsoMu8leg)||(DoubleIsoMu17Mu8_IsoMu17leg && tag_DoubleIsoMu17Mu8_IsoMu8leg));
        passORallPaths = passORDoubleMuons || IsoMu22 || tag_IsoMu22 || IsoTkMu22 || tag_IsoTkMu22 || IsoMu24 || tag_IsoMu24 || IsoTkMu24 || tag_IsoTkMu24;

        
        tOut->Fill();
    }

    tOut->AutoSave(); // according to root tutorial this is the right thing to do
    fOut->Close();
}
