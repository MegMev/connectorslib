///______________________________________________________________________________
///______________________________________________________________________________
///______________________________________________________________________________
///
///
///             RESTSoft : Software for Rare Event Searches with TPCs
///
///             TRestDetectorHitsToTrackFastProcess.h
///
///_______________________________________________________________________________

#ifndef RestCore_TRestDetectorHitsToTrackFastProcess
#define RestCore_TRestDetectorHitsToTrackFastProcess

#include <TRestDetectorHitsEvent.h>
#include <TRestEventProcess.h>
#include <TRestTrackEvent.h>
#include <TVector3.h>

class TRestDetectorHitsToTrackFastProcess : public TRestEventProcess {
   private:
#ifndef __CINT__
    TRestDetectorHitsEvent* fHitsEvent;  //!
    TRestTrackEvent* fTrackEvent;        //!
#endif

    void InitFromConfigFile();

    void Initialize();
    Int_t FindTracks(TRestHits* hits);

   protected:
    // add here the members of your event process

    Double_t fCellResolution;
    Double_t fNetSize;
    TVector3 fNetOrigin;
    Int_t fNodes;

   public:
    inline any GetInputEvent() const { return fHitsEvent; }
    inline any GetOutputEvent() const { return fTrackEvent; }

    void InitProcess();
    TRestEvent* ProcessEvent(TRestEvent* eventInput);
    void EndProcess();
    void LoadDefaultConfig();

    void LoadConfig(std::string configFilename, std::string name = "");

    void PrintMetadata() {
        BeginPrintProcess();

        metadata << " Cell resolution : " << fCellResolution << " mm " << endl;
        metadata << " Net size : " << fNetSize << " mm " << endl;
        metadata << " Net origin : ( " << fNetOrigin.X() << " , " << fNetOrigin.Y() << " , " << fNetOrigin.Z()
                 << " ) mm " << endl;
        metadata << " Number of nodes (per axis) : " << fNodes << endl;

        EndPrintProcess();
    }

    inline const char* GetProcessName() const { return "fastHitsToTrack"; }

    // Constructor
    TRestDetectorHitsToTrackFastProcess();
    TRestDetectorHitsToTrackFastProcess(const char* configFilename);
    // Destructor
    ~TRestDetectorHitsToTrackFastProcess();

    ClassDef(TRestDetectorHitsToTrackFastProcess,
             1);  // Template for a REST "event process" class inherited from
                  // TRestEventProcess
};
#endif
