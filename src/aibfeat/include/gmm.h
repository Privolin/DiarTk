// Copyright (c) 2015 Idiap Research Institute, http://www.idiap.ch/
// Written by Fabio Valente <fabio.valente@idiap.ch>
// Written by Deepu Vijayasenan <dvijayasenan@lsv.uni-saarland.de>
// Written by David Imseng <david.imseng@idiap.ch>
// Written by Srikanth Madikeri <srikanth.madikeri@idiap.ch>
//
// This file is part of the IB Speaker Diarization Toolkit.
//
// IB diarization toolkit is free software: you can redistribute it
// and/or modify it under the terms of the GNU General Public License
// version 3 as published by the Free Software Foundation.
//
// The IB Speaker Diarization Toolkit is distributed in the hope that it
// will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with the IB Speaker Diarization Toolkit. If not, see
// <http://www.gnu.org/licenses/>.


#include "global.h"

class Gaussian
{
   private:
      int DIM;
      float *Mean;
      float *Var;
      float *logVar;
   public:
      Gaussian();
      ~Gaussian();
      void Initialize(int dim);
      void SetMean(const float* mean);
      void SetVar(const float* var);
      const float* GetMean();
      const float*  GetVar();
      float Log_Likelihood(float *feature);
};


class GMM
{
   public:
      int M;
      int DIM;
      float *Weight;
      Gaussian *gArray;   
      float *local_lkld;
      float lkld;
      GMM();
      GMM(const GMM &gmm);
      ~GMM();
      void Copy(GMM temp_gmm);
      float Train(float **data, int nSamples);
      void Initialize(int M, int dim);
      void Initialize(float **data, int count);
      float Log_Likelihood(float *feature);
      float Log_Add(float log_a, float log_b);
};
