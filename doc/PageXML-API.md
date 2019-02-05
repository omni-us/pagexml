# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`define `[`ENH_SAUVOLA`](#intimg_8h_1a191c15bf79ccf7aa9922f22a19c84293)            | Functions related to integral images
`define `[`ENH_SAUVOLA_SDMAX`](#intimg_8h_1a07f0046107cc20abd6cc4b222f281ea6)            | 
`define `[`ENH_WOLF`](#intimg_8h_1a07ab3dec0ed4694d064fdf74c97780e3)            | 
`define `[`TRUE`](#mem_8h_1aa8cecfc5c5c054d2875c03e77b7be15d)            | Functions for allocating memory
`define `[`FALSE`](#mem_8h_1aa93f0eb578d23995850d61f7d61c55c1)            | 
`define `[`FAILURE`](#mem_8h_1a6d58f9ac447476b4e084d7ca383f5183)            | 
`define `[`SUCCESS`](#mem_8h_1aa90cac659d18e8ef6294c7ae337f6b58)            | 
`define `[`IMGIO_GRAYMAX`](#mem_8h_1aa56ff1a6c96071b1875d2e8f8a95fbfa)            | 
`define `[`limit_gray`](#mem_8h_1a9434fec731a98af07c7ad299b5ffdff4)            | 
`define `[`__REUSE_CONTEXT__`](#_page_x_m_l_8cc_1ac9a9b912d159957b6b8712591e950ef4)            | 
`define `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)            | Header file for the [PageXML](#class_page_x_m_l) class
`define `[`throw_runtime_error`](#_page_x_m_l_8h_1a950a67fe0e59f7788788db2c2061d2af)            | 
`define `[`Quantum`](#_text_feat_extractor_8cc_1ad5e97677ea3234923092fa74f9566077)            | [TextFeatExtractor](#class_text_feat_extractor) class
`define `[`__SLANT_PYRAMIDAL__`](#_text_feat_extractor_8cc_1af18630e65d3f15d3a58e93869519be72)            | 
`enum `[`PAGEXML_SETTING`](#_page_x_m_l_8h_1a5079ef3d3aefc01672107a1737c12993)            | 
`enum `[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)            | 
`enum `[`PAGEXML_READ_DIRECTION`](#_page_x_m_l_8h_1a151afb8ef7c7e05585713fafd180a2ea)            | 
`enum `[`PAGEXML_OVERLAP`](#_page_x_m_l_8h_1a8606ef3ee6c75085c7c5d97b79132c50)            | 
`enum `[`TEXTFEAT_TYPE`](#_text_feat_extractor_8h_1a9d37f2a5938d536683837a089301e9aa)            | Header file for the [TextFeatExtractor](#class_text_feat_extractor) class
`enum `[`TEXTFEAT_FORMAT`](#_text_feat_extractor_8h_1ae3b1c3bb02593a1d89768a15b4e3634b)            | 
`public int `[`malloc_II1`](#intimg_8cc_1a471f925f725ece17a6efa35f2f98f6b9)`(int imW,int imH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _II,char clr)`            | Functions related to integral images
`public int `[`malloc_II2`](#intimg_8cc_1ad3629bcb2f4c700ed920934c6532b2bf)`(int imW,int imH,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` *** _II,char clr)`            | 
`public int `[`compII12_graym`](#intimg_8cc_1adc7cc5bb16d72db834ecb5a2362f6678)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt)`            | 
`public int `[`cropsum_II`](#intimg_8cc_1acc3ff7f72afa513b1740679d55db2c06)`(`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,int xmin,int ymin,int cropW,int cropH)`            | 
`public int `[`mean_II`](#intimg_8cc_1ad3ab5bdf8d2a2b9a134d7071f02ffe40)`(`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int xmin,int ymin,int cropW,int cropH,float * _mean)`            | 
`public int `[`sd_II`](#intimg_8cc_1a96130af35be226762469e2da62587abc)`(`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int xmin,int ymin,int cropW,int cropH,float * _sd)`            | 
`public int `[`meanSd_II`](#intimg_8cc_1a7958d9308db69cc012cd487bb7cdb929)`(`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int xmin,int ymin,int cropW,int cropH,float * _mean,float * _sd)`            | 
`public inline static void `[`meanSdCW_II`](#intimg_8cc_1ac75fcaaa89c36c0cab19487022b20a3a)`(int x,int y,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int winS,float * _mean,float * _sd)`            | 
`public inline static `[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` `[`enhSauvola_single`](#intimg_8cc_1aef02d28e9dd30e13039e3f0eee7d25fa)`(int x,int y,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int winS,float prm,float slp,float rng)`            | 
`public inline static `[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` `[`enhWolf_single`](#intimg_8cc_1a165fabf4b0430f5991cbd70ccba9a4eb)`(int x,int y,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int winS,float prm,float slp,float rng,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` minv)`            | 
`public inline static void `[`minValmaxStd`](#intimg_8cc_1adf98ad8735f94f923d100de7adacddf4)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int winS,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` * _minval,float * _maxstd)`            | 
`public int `[`enhLocal_graym`](#intimg_8cc_1afff6015e0086cc7914927371822fb519)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` *** _ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _cnt,int winW,float prm,float slp,int type)`            | 
`public int `[`enhSauvola_sample_prm_graym`](#intimg_8cc_1a7a2561dbab976c2c533a0264691f43ee)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` *** _ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _cnt,int winW,float slp,double * _prm,int subsamp,float prmthr)`            | 
`public int `[`malloc_II1`](#intimg_8h_1a7e097d06d25303749d53864fded05b1b)`(int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _II,char clr)`            | Functions related to integral images
`public int `[`malloc_II2`](#intimg_8h_1a54fcbf20655cb04252b5a3bad5ba5b8e)`(int imgW,int imgH,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` *** _II,char clr)`            | 
`public int `[`compII12_graym`](#intimg_8h_1adc7cc5bb16d72db834ecb5a2362f6678)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt)`            | 
`public int `[`cropsum_II`](#intimg_8h_1acc3ff7f72afa513b1740679d55db2c06)`(`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,int xmin,int ymin,int cropW,int cropH)`            | 
`public int `[`mean_II`](#intimg_8h_1ad3ab5bdf8d2a2b9a134d7071f02ffe40)`(`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int xmin,int ymin,int cropW,int cropH,float * _mean)`            | 
`public int `[`sd_II`](#intimg_8h_1a96130af35be226762469e2da62587abc)`(`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int xmin,int ymin,int cropW,int cropH,float * _sd)`            | 
`public int `[`meanSd_II`](#intimg_8h_1a7958d9308db69cc012cd487bb7cdb929)`(`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int xmin,int ymin,int cropW,int cropH,float * _mean,float * _sd)`            | 
`public int `[`enhLocal_graym`](#intimg_8h_1afff6015e0086cc7914927371822fb519)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` *** _ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _cnt,int winW,float prm,float slp,int type)`            | 
`public int `[`enhSauvola_graym`](#intimg_8h_1a5f6caa9245c41f6693465dabe7c48a6f)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` *** _ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _cnt,int winW,float prm,float slp)`            | 
`public int `[`enhSauvola_sample_prm_graym`](#intimg_8h_1a7a2561dbab976c2c533a0264691f43ee)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` *** _ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _cnt,int winW,float slp,double * _prm,int subsamp,float prmthr)`            | 
`public void `[`bfree`](#mem_8cc_1a804251ffbedb2873777b8f7bb9262082)`(void * mat,int brd)`            | Functions for allocating memory
`public void `[`zeros_I1`](#mem_8cc_1a49f16b6161396edd85a9006ee425aa60)`(`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` * vec,int D)`            | 
`public void `[`zeros_F1`](#mem_8cc_1a8f2ccecabe849edde10175bb5b100372)`(`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` * vec,int D)`            | 
`public void `[`zeros_D1`](#mem_8cc_1ab9ddd5f23ee92bb3a1665859180f41c5)`(`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` * vec,int D)`            | 
`public void `[`copy_I1`](#mem_8cc_1a069c6488219882d4c86bc6d155f7329f)`(`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` * src,int D,`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` * des)`            | 
`public void `[`copy_F1`](#mem_8cc_1a9452b3c24b7f7f584bb37922255d726b)`(`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` * src,int D,`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` * des)`            | 
`public void `[`copy_D1`](#mem_8cc_1adb3199e41aec3c8fbcfde8f5b1308870)`(`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` * src,int D,`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` * des)`            | 
`public int `[`clone_graym`](#mem_8cc_1a3e0c8d75adfd2f16828d33b8c03cb6c6)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** mat,int imW,int imH,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` *** _clon)`            | 
`public int `[`clone_pixelm`](#mem_8cc_1a958ca061f262762644f9ee41eddba0df)`(`[`pixel`](#mem_8h_1a8d2cd65144e7fb3db3b92889edeb1904)` ** mat,int imW,int imH,`[`pixel`](#mem_8h_1a8d2cd65144e7fb3db3b92889edeb1904)` *** _clon)`            | 
`public int `[`malloc_grayv`](#mem_8cc_1ad1bc5adca691a439bd56741a2964272a)`(int size,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** _vec,char clr)`            | 
`public int `[`malloc_pixelv`](#mem_8cc_1ac68abe72ef73f3490895a7570fdd4636)`(int size,`[`pixel`](#mem_8h_1a8d2cd65144e7fb3db3b92889edeb1904)` ** _vec,char clr)`            | 
`public int `[`malloc_I1v`](#mem_8cc_1a046f54f0ed18566eecf6fdbf78437649)`(int size,`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` ** _vec,char clr)`            | 
`public int `[`malloc_F1v`](#mem_8cc_1a88ffb5a5a57c5265e42778e8558313a9)`(int size,`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` ** _vec,char clr)`            | 
`public int `[`malloc_D1v`](#mem_8cc_1a57402f924698b3e3d8d3626f44f9f7ad)`(int size,`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` ** _vec,char clr)`            | 
`public int `[`malloc_iI1v`](#mem_8cc_1a14fd1e4bf10942088c27448e10f3299b)`(int size,`[`iI1`](#structi_i1)` ** _vec,char clr)`            | 
`public int `[`malloc_iF1v`](#mem_8cc_1ab350c930bccb1a4aa2f928a77b341a56)`(int size,`[`iF1`](#structi_f1)` ** _vec,char clr)`            | 
`public int `[`malloc_IV2v`](#mem_8cc_1ab62c4d3385406974a13ad2ce445326ec)`(int size,`[`IV2`](#struct_i_v2)` ** _vec,char clr)`            | 
`public int `[`malloc_graym`](#mem_8cc_1a467c8f80c6e9b5e5edde9bb95e9e0813)`(int imW,int imH,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` *** _im,char clr)`            | 
`public int `[`malloc_pixelm`](#mem_8cc_1a5af49b10bcac51b8bee89d137094911b)`(int imW,int imH,`[`pixel`](#mem_8h_1a8d2cd65144e7fb3db3b92889edeb1904)` *** _im,char clr)`            | 
`public int `[`malloc_I1m`](#mem_8cc_1a114839923279fad737ba92f892a4a5e2)`(int R,int C,`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` *** _mat,char clr)`            | 
`public int `[`malloc_F1m`](#mem_8cc_1afc96f3520676803230236c84515f4ae9)`(int R,int C,`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` *** _mat,char clr)`            | 
`public int `[`malloc_D1m`](#mem_8cc_1ae9ee6ca94e22c18b7d1fc71ecc8984fd)`(int R,int C,`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` *** _mat,char clr)`            | 
`public int `[`malloc_F1t`](#mem_8cc_1aaf8a40c7bfea53a05814c3fc7f298881)`(int D,`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` *** _mat,char clr)`            | 
`public int `[`malloc_D1t`](#mem_8cc_1a7bbc91755cbd9ca19c451e9969d1e264)`(int D,`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` *** _mat,char clr)`            | 
`public void `[`nullfree`](#mem_8cc_1a6aebb3bdc6c6c84d19e7938cdda52f28)`(void * ptr)`            | 
`public int `[`mclone`](#mem_8cc_1af8c488b80769c8ca4860d995b4d45ed6)`(char ** mat,int R,int C,int size,char *** _clon)`            | 
`public int `[`mem`](#mem_8cc_1ac1447d2f2eb5ed26ed86ac81bbbde0f5)`(int size,char clr,char ** _p)`            | 
`public int `[`mmem`](#mem_8cc_1aba14ccbeca39769f8e14d99ba73bd1bb)`(int R,int C,int size,char clr,char *** _mat)`            | 
`public int `[`bmem`](#mem_8cc_1aaeca8c0eda4783d3da8f11e8e952c52e)`(int R,int C,int size,char clr,int brd,char *** _mat)`            | 
`public int `[`tmem`](#mem_8cc_1a66f4d65fa18163eeafed4deb2865e1c0)`(int D,int size,char clr,char *** _mat)`            | 
`public void `[`vrmem_index`](#mem_8cc_1a5abb4274279b20e09acbb986f8a570c4)`(int size,int * R,int C,char ** mat)`            | 
`public int `[`vrmem`](#mem_8cc_1aa410e5fb6c64b8dfdd17cadf346f82aa)`(int size,int tnnz,int * R,int C,char clr,char *** _mat,int ** _R)`            | 
`public void `[`bfree`](#mem_8h_1a804251ffbedb2873777b8f7bb9262082)`(void * mat,int brd)`            | Functions for allocating memory
`public void `[`zeros_I1`](#mem_8h_1a49f16b6161396edd85a9006ee425aa60)`(`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` * vec,int D)`            | 
`public void `[`zeros_F1`](#mem_8h_1a8f2ccecabe849edde10175bb5b100372)`(`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` * vec,int D)`            | 
`public void `[`zeros_D1`](#mem_8h_1ab9ddd5f23ee92bb3a1665859180f41c5)`(`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` * vec,int D)`            | 
`public void `[`copy_I1`](#mem_8h_1a069c6488219882d4c86bc6d155f7329f)`(`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` * src,int D,`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` * des)`            | 
`public void `[`copy_F1`](#mem_8h_1a9452b3c24b7f7f584bb37922255d726b)`(`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` * src,int D,`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` * des)`            | 
`public void `[`copy_D1`](#mem_8h_1adb3199e41aec3c8fbcfde8f5b1308870)`(`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` * src,int D,`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` * des)`            | 
`public int `[`clone_graym`](#mem_8h_1a3e0c8d75adfd2f16828d33b8c03cb6c6)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** mat,int imW,int imH,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` *** _clon)`            | 
`public int `[`clone_pixelm`](#mem_8h_1a958ca061f262762644f9ee41eddba0df)`(`[`pixel`](#mem_8h_1a8d2cd65144e7fb3db3b92889edeb1904)` ** mat,int imW,int imH,`[`pixel`](#mem_8h_1a8d2cd65144e7fb3db3b92889edeb1904)` *** _clon)`            | 
`public int `[`malloc_grayv`](#mem_8h_1ad1bc5adca691a439bd56741a2964272a)`(int size,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** _vec,char clr)`            | 
`public int `[`malloc_pixelv`](#mem_8h_1ac68abe72ef73f3490895a7570fdd4636)`(int size,`[`pixel`](#mem_8h_1a8d2cd65144e7fb3db3b92889edeb1904)` ** _vec,char clr)`            | 
`public int `[`malloc_I1v`](#mem_8h_1a046f54f0ed18566eecf6fdbf78437649)`(int size,`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` ** _vec,char clr)`            | 
`public int `[`malloc_F1v`](#mem_8h_1a88ffb5a5a57c5265e42778e8558313a9)`(int size,`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` ** _vec,char clr)`            | 
`public int `[`malloc_D1v`](#mem_8h_1a57402f924698b3e3d8d3626f44f9f7ad)`(int size,`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` ** _vec,char clr)`            | 
`public int `[`malloc_iI1v`](#mem_8h_1a14fd1e4bf10942088c27448e10f3299b)`(int size,`[`iI1`](#structi_i1)` ** _vec,char clr)`            | 
`public int `[`malloc_iF1v`](#mem_8h_1ab350c930bccb1a4aa2f928a77b341a56)`(int size,`[`iF1`](#structi_f1)` ** _vec,char clr)`            | 
`public int `[`malloc_IV2v`](#mem_8h_1ab62c4d3385406974a13ad2ce445326ec)`(int size,`[`IV2`](#struct_i_v2)` ** _vec,char clr)`            | 
`public int `[`malloc_graym`](#mem_8h_1a467c8f80c6e9b5e5edde9bb95e9e0813)`(int imW,int imH,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` *** _im,char clr)`            | 
`public int `[`malloc_pixelm`](#mem_8h_1a5af49b10bcac51b8bee89d137094911b)`(int imW,int imH,`[`pixel`](#mem_8h_1a8d2cd65144e7fb3db3b92889edeb1904)` *** _im,char clr)`            | 
`public int `[`malloc_I1m`](#mem_8h_1a114839923279fad737ba92f892a4a5e2)`(int R,int C,`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` *** _mat,char clr)`            | 
`public int `[`malloc_F1m`](#mem_8h_1afc96f3520676803230236c84515f4ae9)`(int R,int C,`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` *** _mat,char clr)`            | 
`public int `[`malloc_D1m`](#mem_8h_1ae9ee6ca94e22c18b7d1fc71ecc8984fd)`(int R,int C,`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` *** _mat,char clr)`            | 
`public int `[`malloc_F1t`](#mem_8h_1aaf8a40c7bfea53a05814c3fc7f298881)`(int D,`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` *** _mat,char clr)`            | 
`public int `[`malloc_D1t`](#mem_8h_1a7bbc91755cbd9ca19c451e9969d1e264)`(int D,`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` *** _mat,char clr)`            | 
`public void `[`nullfree`](#mem_8h_1a6aebb3bdc6c6c84d19e7938cdda52f28)`(void * ptr)`            | 
`public int `[`mclone`](#mem_8h_1af8c488b80769c8ca4860d995b4d45ed6)`(char ** mat,int R,int C,int size,char *** _clon)`            | 
`public int `[`mem`](#mem_8h_1ac1447d2f2eb5ed26ed86ac81bbbde0f5)`(int size,char clr,char ** _p)`            | 
`public int `[`mmem`](#mem_8h_1aba14ccbeca39769f8e14d99ba73bd1bb)`(int R,int C,int size,char clr,char *** _mat)`            | 
`public int `[`bmem`](#mem_8h_1aaeca8c0eda4783d3da8f11e8e952c52e)`(int R,int C,int size,char clr,int brd,char *** _mat)`            | 
`public int `[`tmem`](#mem_8h_1a66f4d65fa18163eeafed4deb2865e1c0)`(int D,int size,char clr,char *** _mat)`            | 
`public void `[`vrmem_index`](#mem_8h_1a5abb4274279b20e09acbb986f8a570c4)`(int size,int * R,int C,char ** mat)`            | 
`public int `[`vrmem`](#mem_8h_1aa410e5fb6c64b8dfdd17cadf346f82aa)`(int size,int tnnz,int * R,int C,char clr,char *** _mat,int ** _R)`            | 
`public regex `[`reXheight`](#_page_x_m_l_8cc_1a726c6cc001ee5d420a795decf8fd680d)`(".*x-height: *([0-9.]+) *px;.*")`            | 
`public regex `[`reRotation`](#_page_x_m_l_8cc_1ace361379b17a512eaf8ef91bc8ee0914)`(".*readingOrientation: *([0-9.]+) *;.*")`            | 
`public regex `[`reDirection`](#_page_x_m_l_8cc_1a3eab4de6fb9cae3e28f0fc041a4da1cb)`(".*readingDirection: *([lrt]t[rlb]) *;.*")`            | 
`public regex `[`reFileExt`](#_page_x_m_l_8cc_1ad5282dbd2e59128edd3d72ba918edaac)`("\")`            | 
`public regex `[`reInvalidBaseChars`](#_page_x_m_l_8cc_1aa7ad44cbc1ef82ed4fcadaec999ed6ad)`(" ")`            | 
`public regex `[`reImagePageNum`](#_page_x_m_l_8cc_1a4714abac484a975e267fc6c240351a20)`("(.*)\0-9]+)\)`            | 
`public regex `[`reIsPdf`](#_page_x_m_l_8cc_1ac72179235a1c7e62570ea65b1055be4c)`(".+\f(\-9]+\0,1}$",std::regex::icase)`            | 
`public regex `[`reIsTiff`](#_page_x_m_l_8cc_1a192ae590965b3d04d774f30aff3088bd)`(".+\f{1,2}(\-9]+\0,1}$",std::regex::icase)`            | 
`public static void `[`validationErrorFunc`](#_page_x_m_l_8cc_1a42193d6b48be67e3479f98616552874c)`(void *ctx  __attribute__,const char * msg,...)`            | Schema validation ///.
`public static void `[`validationWarningFunc`](#_page_x_m_l_8cc_1a4a5264df828c064fb9d585c736895e78)`(void *ctx  __attribute__,const char * msg,...)`            | 
`public void `[`mktemp`](#_page_x_m_l_8cc_1a54bdec4c6dd5a11b008fc79598dfbd64)`(const char * tempbase,char * tempname)`            | Function that creates a temporal file using the mktemp command
`public static std::vector< double > `[`project_2d_to_1d`](#_page_x_m_l_8cc_1aa295be52a9f7d03cb5a745bc6b2550e9)`(std::vector< cv::Point2f > points,cv::Point2f axis,double yoffset)`            | Projects points onto a line defined by a direction and y-offset
`public inline static double `[`angleDiff`](#_page_x_m_l_8cc_1a61fc06d078d73deb50298f47d612eedd)`(double a1,double a2)`            | Computes the difference between two angles [-PI,PI] accounting for the discontinuity
`public inline static double `[`intersection_1d`](#_page_x_m_l_8cc_1a8cb2d5f6e60399cf47f11bb9201fb4dc)`(double & a1,double & a2,double & b1,double & b2)`            | Computes the 1D intersection
`public inline static double `[`IoU_1d`](#_page_x_m_l_8cc_1ac09c1ca85100d59d39f77e7f545eca8d)`(double a1,double a2,double b1,double b2)`            | Computes the 1D intersection over union
`public double `[`withinSegment`](#_page_x_m_l_8cc_1a01aee68a0af5ee992c2f6b499b4a5558)`(cv::Point2f segm_start,cv::Point2f segm_end,cv::Point2f point)`            | Checks if a point is within a line segment
`public const Magick::Color `[`colorWhite`](#_text_feat_extractor_8cc_1a1c101d5ae529d47ee2630004d33ed452)`("white")`            | 
`public const Magick::Color `[`colorBlack`](#_text_feat_extractor_8cc_1a52730ed7e5affa8a15f42e952281b0f5)`("black")`            | 
`public inline static void `[`print_int`](#_text_feat_extractor_8cc_1ac53eacb3014c40030f7474620c78fbac)`(long data,FILE * file)`            | Loaders ///.
`public inline static void `[`print_short`](#_text_feat_extractor_8cc_1ac814fb690cd4494501cc3de16c920276)`(int data,FILE * file)`            | Prints an int in binary.
`public inline static void `[`print_float`](#_text_feat_extractor_8cc_1a2dbcb88814027a8aec1d924775a57737)`(float data,FILE * file)`            | Prints a float in binary.
`public static void `[`print_features_htk`](#_text_feat_extractor_8cc_1a521b3512933909ece7bd18cf625ad5fe)`(const cv::Mat & feats,FILE * file)`            | Prints features to a file stream using HTK format.
`public static void `[`print_features_ascii`](#_text_feat_extractor_8cc_1ae3a1fa6530381f534ec5e2ff90495b8e)`(const cv::Mat & feats,FILE * file)`            | Prints features to a file stream using ASCII format.
`public static void `[`magick2cvmat8u`](#_text_feat_extractor_8cc_1ac0d8f9ed183c953d3ced538c9f1ce002)`(Magick::Image & image,cv::Mat & cvimg)`            | Image processing ///.
`public static void `[`magick2cvmat8uc3`](#_text_feat_extractor_8cc_1abd4530acf52f35d5ba38b9f3038b0ab1)`(Magick::Image & image,cv::Mat & cvimg)`            | Copies image data from Magick::Image to an OpenCV Mat.
`public static void `[`magick2graym`](#_text_feat_extractor_8cc_1a3033920ea2862f45dfd32ec026fa8088)`(Magick::Image & image,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` **& gimg,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` *** _alpha)`            | Copies image data from Magick::Image to an unsigned char matrix.
`public inline static int `[`to16bits`](#_text_feat_extractor_8cc_1a1a811eaff5dda86d249594fe3d992259)`(int val)`            | Converts unsigned char to 16-bits.
`public static void `[`graym2magick`](#_text_feat_extractor_8cc_1a3d05d264e460dccb52ae7b0512f658f1)`(Magick::Image & image,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** gimg,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alpha)`            | Copies image data from unsigned char matrix to Magick::Image.
`public static void `[`grayms2magick`](#_text_feat_extractor_8cc_1a066bfd0260bf6e3dd2ec159f26dfc9c3)`(Magick::Image & image,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** rimg,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** gimg,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** bimg,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alpha)`            | Copies image data from unsigned char matrix to Magick::Image.
`public static void `[`cvmat8u2magick`](#_text_feat_extractor_8cc_1af1756b455bc263fea7aadde3a4e847ae)`(Magick::Image & image,cv::Mat & cvimg)`            | Copies image data from an OpenCV Mat to Magick::Image.
`public static void `[`cvmat8uc32magick`](#_text_feat_extractor_8cc_1a1bb4e2cb8ba2fa857e784c0dfb6a3761)`(Magick::Image & image,cv::Mat & cvimg)`            | Copies image data from an OpenCV Mat to Magick::Image.
`public static void `[`cvmat8u2magick`](#_text_feat_extractor_8cc_1accdc54fbd584e586cad5bbdb08035659)`(Magick::Image & image,cv::Mat & cvimg,cv::Mat & cvimg_alpha)`            | Copies image data from an OpenCV Mat to Magick::Image.
`public static void `[`enhance`](#_text_feat_extractor_8cc_1a81f14f6e96fbff1e6d74739c0c93f358)`(Magick::Image & image,int winW,double prm1,double slp,int type,double prm0,double prm2)`            | Does a local enhancement of a text image.
`public int `[`rlsa4_graym`](#_text_feat_extractor_8cc_1a3b1901a411f56afa5aad0b3fe0d5b5f0)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,int imgW,int imgH,char op,int * lengths,bool negate,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** res)`            | Four directional RLSA algorithm.
`public inline static void `[`findMinMax`](#_text_feat_extractor_8cc_1a83ec3f37e202c24e48620142056dd6ab)`(int size,double * vals,bool * isset,double * _minval,double * _maxval,int * _minidx,int * _maxidx)`            | 
`public static double `[`estimateSlant`](#_text_feat_extractor_8cc_1af850a209ee624d37c3f427125a67f80e)`(Magick::Image & image,double amin,double amax,double astep,int hsteps,double hfact)`            | Estimates the slant angle of an image containing handwritten text.
`public void `[`findOuterContours`](#_text_feat_extractor_8cc_1af7639c4a00fe54f47a88eef066ef1a0b)`(Magick::Image & img,vector< vector< cv::Point > > & contours,int method,double eps)`            | Gets outer contour points of connected components in an image, optionally approximating it.
`public static void `[`joinComponents`](#_text_feat_extractor_8cc_1a4da782c15ab0baee562d0370e6297e02)`(Magick::Image & img)`            | Joints all connected components in an image using 1px thick lines between nearest contour points.
`public bool `[`toGrayscale`](#_text_feat_extractor_8cc_1a360080636b9ecf83ebbf859d652ffedc)`(cv::Mat & image,cv::Mat & image_alpha)`            | Converts image to grayscale preserving alpha channel if present.
`public bool `[`flattenImage`](#_text_feat_extractor_8cc_1ab109c954f49e5729f8adc65382209b34)`(Magick::Image & image,const Magick::Color * color)`            | Removes alpha channel, setting all transparent regions to the background color.
`class `[`OGRMultiLineString_`](#class_o_g_r_multi_line_string__) | 
`class `[`OGRMultiPolygon_`](#class_o_g_r_multi_polygon__) | 
`class `[`PageXML`](#class_page_x_m_l) | 
`class `[`TextFeatExtractor`](#class_text_feat_extractor) | 
`struct `[`iF1`](#structi_f1) | 
`struct `[`iI1`](#structi_i1) | 
`struct `[`IV2`](#struct_i_v2) | 
`struct `[`NamedImage`](#struct_named_image) | 
`struct `[`rgb`](#structrgb) | 

## Members

#### `define `[`ENH_SAUVOLA`](#intimg_8h_1a191c15bf79ccf7aa9922f22a19c84293) 

Functions related to integral images

Version2018.11.13

Copyright (c) 2004-present, Mauricio Villegas [mauricio_ville@yahoo.com](mailto:mauricio_ville@yahoo.com)  MIT License

#### `define `[`ENH_SAUVOLA_SDMAX`](#intimg_8h_1a07f0046107cc20abd6cc4b222f281ea6) 

#### `define `[`ENH_WOLF`](#intimg_8h_1a07ab3dec0ed4694d064fdf74c97780e3) 

#### `define `[`TRUE`](#mem_8h_1aa8cecfc5c5c054d2875c03e77b7be15d) 

Functions for allocating memory

Version2018.11.13

Copyright (c) 2004-present, Mauricio Villegas [mauricio_ville@yahoo.com](mailto:mauricio_ville@yahoo.com)  MIT License

#### `define `[`FALSE`](#mem_8h_1aa93f0eb578d23995850d61f7d61c55c1) 

#### `define `[`FAILURE`](#mem_8h_1a6d58f9ac447476b4e084d7ca383f5183) 

#### `define `[`SUCCESS`](#mem_8h_1aa90cac659d18e8ef6294c7ae337f6b58) 

#### `define `[`IMGIO_GRAYMAX`](#mem_8h_1aa56ff1a6c96071b1875d2e8f8a95fbfa) 

#### `define `[`limit_gray`](#mem_8h_1a9434fec731a98af07c7ad299b5ffdff4) 

#### `define `[`__REUSE_CONTEXT__`](#_page_x_m_l_8cc_1ac9a9b912d159957b6b8712591e950ef4) 

#### `define `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80) 

Header file for the [PageXML](#class_page_x_m_l) class

Version2019.02.05

Copyright (c) 2016-present, Mauricio Villegas [mauricio_ville@yahoo.com](mailto:mauricio_ville@yahoo.com)  MIT License

#### `define `[`throw_runtime_error`](#_page_x_m_l_8h_1a950a67fe0e59f7788788db2c2061d2af) 

#### `define `[`Quantum`](#_text_feat_extractor_8cc_1ad5e97677ea3234923092fa74f9566077) 

[TextFeatExtractor](#class_text_feat_extractor) class

Version2019.01.25

Copyright (c) 2016-present, Mauricio Villegas [mauricio_ville@yahoo.com](mailto:mauricio_ville@yahoo.com)  MIT License

#### `define `[`__SLANT_PYRAMIDAL__`](#_text_feat_extractor_8cc_1af18630e65d3f15d3a58e93869519be72) 

#### `enum `[`PAGEXML_SETTING`](#_page_x_m_l_8h_1a5079ef3d3aefc01672107a1737c12993) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
PAGEXML_SETTING_INDENT            | 
PAGEXML_SETTING_PAGENS            | 
PAGEXML_SETTING_GRAYIMG            | 

#### `enum `[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
PAGEXML_INSERT_APPEND            | 
PAGEXML_INSERT_PREPEND            | 
PAGEXML_INSERT_NEXTSIB            | 
PAGEXML_INSERT_PREVSIB            | 

#### `enum `[`PAGEXML_READ_DIRECTION`](#_page_x_m_l_8h_1a151afb8ef7c7e05585713fafd180a2ea) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
PAGEXML_READ_DIRECTION_LTR            | 
PAGEXML_READ_DIRECTION_RTL            | 
PAGEXML_READ_DIRECTION_TTB            | 
PAGEXML_READ_DIRECTION_BTT            | 

#### `enum `[`PAGEXML_OVERLAP`](#_page_x_m_l_8h_1a8606ef3ee6c75085c7c5d97b79132c50) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
PAGEXML_OVERLAP_COORDS_IOU            | 
PAGEXML_OVERLAP_COORDS_ISECT            | 
PAGEXML_OVERLAP_COORDS_IWA            | 
PAGEXML_OVERLAP_BASELINE_IWA            | 
PAGEXML_OVERLAP_COORDS_BASELINE_IWA            | 

#### `enum `[`TEXTFEAT_TYPE`](#_text_feat_extractor_8h_1a9d37f2a5938d536683837a089301e9aa) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
TEXTFEAT_TYPE_DOTMATRIX            | 
TEXTFEAT_TYPE_RAW            | 

Header file for the [TextFeatExtractor](#class_text_feat_extractor) class

Version2019.01.25

Copyright (c) 2016-present, Mauricio Villegas [mauricio_ville@yahoo.com](mailto:mauricio_ville@yahoo.com)  MIT License

#### `enum `[`TEXTFEAT_FORMAT`](#_text_feat_extractor_8h_1ae3b1c3bb02593a1d89768a15b4e3634b) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
TEXTFEAT_FORMAT_ASCII            | 
TEXTFEAT_FORMAT_HTK            | 
TEXTFEAT_FORMAT_IMAGE            | 

#### `public int `[`malloc_II1`](#intimg_8cc_1a471f925f725ece17a6efa35f2f98f6b9)`(int imW,int imH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _II,char clr)` 

Functions related to integral images

Version2018.11.13

Copyright (c) 2004-present, Mauricio Villegas [mauricio_ville@yahoo.com](mailto:mauricio_ville@yahoo.com)  MIT License

#### `public int `[`malloc_II2`](#intimg_8cc_1ad3629bcb2f4c700ed920934c6532b2bf)`(int imW,int imH,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` *** _II,char clr)` 

#### `public int `[`compII12_graym`](#intimg_8cc_1adc7cc5bb16d72db834ecb5a2362f6678)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt)` 

#### `public int `[`cropsum_II`](#intimg_8cc_1acc3ff7f72afa513b1740679d55db2c06)`(`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,int xmin,int ymin,int cropW,int cropH)` 

#### `public int `[`mean_II`](#intimg_8cc_1ad3ab5bdf8d2a2b9a134d7071f02ffe40)`(`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int xmin,int ymin,int cropW,int cropH,float * _mean)` 

#### `public int `[`sd_II`](#intimg_8cc_1a96130af35be226762469e2da62587abc)`(`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int xmin,int ymin,int cropW,int cropH,float * _sd)` 

#### `public int `[`meanSd_II`](#intimg_8cc_1a7958d9308db69cc012cd487bb7cdb929)`(`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int xmin,int ymin,int cropW,int cropH,float * _mean,float * _sd)` 

#### `public inline static void `[`meanSdCW_II`](#intimg_8cc_1ac75fcaaa89c36c0cab19487022b20a3a)`(int x,int y,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int winS,float * _mean,float * _sd)` 

#### `public inline static `[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` `[`enhSauvola_single`](#intimg_8cc_1aef02d28e9dd30e13039e3f0eee7d25fa)`(int x,int y,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int winS,float prm,float slp,float rng)` 

#### `public inline static `[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` `[`enhWolf_single`](#intimg_8cc_1a165fabf4b0430f5991cbd70ccba9a4eb)`(int x,int y,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int winS,float prm,float slp,float rng,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` minv)` 

#### `public inline static void `[`minValmaxStd`](#intimg_8cc_1adf98ad8735f94f923d100de7adacddf4)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int winS,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` * _minval,float * _maxstd)` 

#### `public int `[`enhLocal_graym`](#intimg_8cc_1afff6015e0086cc7914927371822fb519)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` *** _ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _cnt,int winW,float prm,float slp,int type)` 

#### `public int `[`enhSauvola_sample_prm_graym`](#intimg_8cc_1a7a2561dbab976c2c533a0264691f43ee)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` *** _ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _cnt,int winW,float slp,double * _prm,int subsamp,float prmthr)` 

#### `public int `[`malloc_II1`](#intimg_8h_1a7e097d06d25303749d53864fded05b1b)`(int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _II,char clr)` 

Functions related to integral images

Version2018.11.13

Copyright (c) 2004-present, Mauricio Villegas [mauricio_ville@yahoo.com](mailto:mauricio_ville@yahoo.com)  MIT License

#### `public int `[`malloc_II2`](#intimg_8h_1a54fcbf20655cb04252b5a3bad5ba5b8e)`(int imgW,int imgH,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` *** _II,char clr)` 

#### `public int `[`compII12_graym`](#intimg_8h_1adc7cc5bb16d72db834ecb5a2362f6678)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt)` 

#### `public int `[`cropsum_II`](#intimg_8h_1acc3ff7f72afa513b1740679d55db2c06)`(`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,int xmin,int ymin,int cropW,int cropH)` 

#### `public int `[`mean_II`](#intimg_8h_1ad3ab5bdf8d2a2b9a134d7071f02ffe40)`(`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int xmin,int ymin,int cropW,int cropH,float * _mean)` 

#### `public int `[`sd_II`](#intimg_8h_1a96130af35be226762469e2da62587abc)`(`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int xmin,int ymin,int cropW,int cropH,float * _sd)` 

#### `public int `[`meanSd_II`](#intimg_8h_1a7958d9308db69cc012cd487bb7cdb929)`(`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` ** ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` ** cnt,int xmin,int ymin,int cropW,int cropH,float * _mean,float * _sd)` 

#### `public int `[`enhLocal_graym`](#intimg_8h_1afff6015e0086cc7914927371822fb519)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` *** _ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _cnt,int winW,float prm,float slp,int type)` 

#### `public int `[`enhSauvola_graym`](#intimg_8h_1a5f6caa9245c41f6693465dabe7c48a6f)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` *** _ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _cnt,int winW,float prm,float slp)` 

#### `public int `[`enhSauvola_sample_prm_graym`](#intimg_8h_1a7a2561dbab976c2c533a0264691f43ee)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alph,int imgW,int imgH,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _ii1,`[`II2`](#intimg_8h_1aa52d4e13ca6c777cdd680ce7dca84a7f)` *** _ii2,`[`II1`](#intimg_8h_1afd470c7bf8ddd891ce2cb9eb8d87b41a)` *** _cnt,int winW,float slp,double * _prm,int subsamp,float prmthr)` 

#### `public void `[`bfree`](#mem_8cc_1a804251ffbedb2873777b8f7bb9262082)`(void * mat,int brd)` 

Functions for allocating memory

Version2018.11.13

Copyright (c) 2004-present, Mauricio Villegas [mauricio_ville@yahoo.com](mailto:mauricio_ville@yahoo.com)  MIT License

#### `public void `[`zeros_I1`](#mem_8cc_1a49f16b6161396edd85a9006ee425aa60)`(`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` * vec,int D)` 

#### `public void `[`zeros_F1`](#mem_8cc_1a8f2ccecabe849edde10175bb5b100372)`(`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` * vec,int D)` 

#### `public void `[`zeros_D1`](#mem_8cc_1ab9ddd5f23ee92bb3a1665859180f41c5)`(`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` * vec,int D)` 

#### `public void `[`copy_I1`](#mem_8cc_1a069c6488219882d4c86bc6d155f7329f)`(`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` * src,int D,`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` * des)` 

#### `public void `[`copy_F1`](#mem_8cc_1a9452b3c24b7f7f584bb37922255d726b)`(`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` * src,int D,`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` * des)` 

#### `public void `[`copy_D1`](#mem_8cc_1adb3199e41aec3c8fbcfde8f5b1308870)`(`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` * src,int D,`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` * des)` 

#### `public int `[`clone_graym`](#mem_8cc_1a3e0c8d75adfd2f16828d33b8c03cb6c6)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** mat,int imW,int imH,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` *** _clon)` 

#### `public int `[`clone_pixelm`](#mem_8cc_1a958ca061f262762644f9ee41eddba0df)`(`[`pixel`](#mem_8h_1a8d2cd65144e7fb3db3b92889edeb1904)` ** mat,int imW,int imH,`[`pixel`](#mem_8h_1a8d2cd65144e7fb3db3b92889edeb1904)` *** _clon)` 

#### `public int `[`malloc_grayv`](#mem_8cc_1ad1bc5adca691a439bd56741a2964272a)`(int size,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** _vec,char clr)` 

#### `public int `[`malloc_pixelv`](#mem_8cc_1ac68abe72ef73f3490895a7570fdd4636)`(int size,`[`pixel`](#mem_8h_1a8d2cd65144e7fb3db3b92889edeb1904)` ** _vec,char clr)` 

#### `public int `[`malloc_I1v`](#mem_8cc_1a046f54f0ed18566eecf6fdbf78437649)`(int size,`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` ** _vec,char clr)` 

#### `public int `[`malloc_F1v`](#mem_8cc_1a88ffb5a5a57c5265e42778e8558313a9)`(int size,`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` ** _vec,char clr)` 

#### `public int `[`malloc_D1v`](#mem_8cc_1a57402f924698b3e3d8d3626f44f9f7ad)`(int size,`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` ** _vec,char clr)` 

#### `public int `[`malloc_iI1v`](#mem_8cc_1a14fd1e4bf10942088c27448e10f3299b)`(int size,`[`iI1`](#structi_i1)` ** _vec,char clr)` 

#### `public int `[`malloc_iF1v`](#mem_8cc_1ab350c930bccb1a4aa2f928a77b341a56)`(int size,`[`iF1`](#structi_f1)` ** _vec,char clr)` 

#### `public int `[`malloc_IV2v`](#mem_8cc_1ab62c4d3385406974a13ad2ce445326ec)`(int size,`[`IV2`](#struct_i_v2)` ** _vec,char clr)` 

#### `public int `[`malloc_graym`](#mem_8cc_1a467c8f80c6e9b5e5edde9bb95e9e0813)`(int imW,int imH,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` *** _im,char clr)` 

#### `public int `[`malloc_pixelm`](#mem_8cc_1a5af49b10bcac51b8bee89d137094911b)`(int imW,int imH,`[`pixel`](#mem_8h_1a8d2cd65144e7fb3db3b92889edeb1904)` *** _im,char clr)` 

#### `public int `[`malloc_I1m`](#mem_8cc_1a114839923279fad737ba92f892a4a5e2)`(int R,int C,`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` *** _mat,char clr)` 

#### `public int `[`malloc_F1m`](#mem_8cc_1afc96f3520676803230236c84515f4ae9)`(int R,int C,`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` *** _mat,char clr)` 

#### `public int `[`malloc_D1m`](#mem_8cc_1ae9ee6ca94e22c18b7d1fc71ecc8984fd)`(int R,int C,`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` *** _mat,char clr)` 

#### `public int `[`malloc_F1t`](#mem_8cc_1aaf8a40c7bfea53a05814c3fc7f298881)`(int D,`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` *** _mat,char clr)` 

#### `public int `[`malloc_D1t`](#mem_8cc_1a7bbc91755cbd9ca19c451e9969d1e264)`(int D,`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` *** _mat,char clr)` 

#### `public void `[`nullfree`](#mem_8cc_1a6aebb3bdc6c6c84d19e7938cdda52f28)`(void * ptr)` 

#### `public int `[`mclone`](#mem_8cc_1af8c488b80769c8ca4860d995b4d45ed6)`(char ** mat,int R,int C,int size,char *** _clon)` 

#### `public int `[`mem`](#mem_8cc_1ac1447d2f2eb5ed26ed86ac81bbbde0f5)`(int size,char clr,char ** _p)` 

#### `public int `[`mmem`](#mem_8cc_1aba14ccbeca39769f8e14d99ba73bd1bb)`(int R,int C,int size,char clr,char *** _mat)` 

#### `public int `[`bmem`](#mem_8cc_1aaeca8c0eda4783d3da8f11e8e952c52e)`(int R,int C,int size,char clr,int brd,char *** _mat)` 

#### `public int `[`tmem`](#mem_8cc_1a66f4d65fa18163eeafed4deb2865e1c0)`(int D,int size,char clr,char *** _mat)` 

#### `public void `[`vrmem_index`](#mem_8cc_1a5abb4274279b20e09acbb986f8a570c4)`(int size,int * R,int C,char ** mat)` 

#### `public int `[`vrmem`](#mem_8cc_1aa410e5fb6c64b8dfdd17cadf346f82aa)`(int size,int tnnz,int * R,int C,char clr,char *** _mat,int ** _R)` 

#### `public void `[`bfree`](#mem_8h_1a804251ffbedb2873777b8f7bb9262082)`(void * mat,int brd)` 

Functions for allocating memory

Version2018.11.13

Copyright (c) 2004-present, Mauricio Villegas [mauricio_ville@yahoo.com](mailto:mauricio_ville@yahoo.com)  MIT License

#### `public void `[`zeros_I1`](#mem_8h_1a49f16b6161396edd85a9006ee425aa60)`(`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` * vec,int D)` 

#### `public void `[`zeros_F1`](#mem_8h_1a8f2ccecabe849edde10175bb5b100372)`(`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` * vec,int D)` 

#### `public void `[`zeros_D1`](#mem_8h_1ab9ddd5f23ee92bb3a1665859180f41c5)`(`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` * vec,int D)` 

#### `public void `[`copy_I1`](#mem_8h_1a069c6488219882d4c86bc6d155f7329f)`(`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` * src,int D,`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` * des)` 

#### `public void `[`copy_F1`](#mem_8h_1a9452b3c24b7f7f584bb37922255d726b)`(`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` * src,int D,`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` * des)` 

#### `public void `[`copy_D1`](#mem_8h_1adb3199e41aec3c8fbcfde8f5b1308870)`(`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` * src,int D,`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` * des)` 

#### `public int `[`clone_graym`](#mem_8h_1a3e0c8d75adfd2f16828d33b8c03cb6c6)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** mat,int imW,int imH,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` *** _clon)` 

#### `public int `[`clone_pixelm`](#mem_8h_1a958ca061f262762644f9ee41eddba0df)`(`[`pixel`](#mem_8h_1a8d2cd65144e7fb3db3b92889edeb1904)` ** mat,int imW,int imH,`[`pixel`](#mem_8h_1a8d2cd65144e7fb3db3b92889edeb1904)` *** _clon)` 

#### `public int `[`malloc_grayv`](#mem_8h_1ad1bc5adca691a439bd56741a2964272a)`(int size,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** _vec,char clr)` 

#### `public int `[`malloc_pixelv`](#mem_8h_1ac68abe72ef73f3490895a7570fdd4636)`(int size,`[`pixel`](#mem_8h_1a8d2cd65144e7fb3db3b92889edeb1904)` ** _vec,char clr)` 

#### `public int `[`malloc_I1v`](#mem_8h_1a046f54f0ed18566eecf6fdbf78437649)`(int size,`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` ** _vec,char clr)` 

#### `public int `[`malloc_F1v`](#mem_8h_1a88ffb5a5a57c5265e42778e8558313a9)`(int size,`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` ** _vec,char clr)` 

#### `public int `[`malloc_D1v`](#mem_8h_1a57402f924698b3e3d8d3626f44f9f7ad)`(int size,`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` ** _vec,char clr)` 

#### `public int `[`malloc_iI1v`](#mem_8h_1a14fd1e4bf10942088c27448e10f3299b)`(int size,`[`iI1`](#structi_i1)` ** _vec,char clr)` 

#### `public int `[`malloc_iF1v`](#mem_8h_1ab350c930bccb1a4aa2f928a77b341a56)`(int size,`[`iF1`](#structi_f1)` ** _vec,char clr)` 

#### `public int `[`malloc_IV2v`](#mem_8h_1ab62c4d3385406974a13ad2ce445326ec)`(int size,`[`IV2`](#struct_i_v2)` ** _vec,char clr)` 

#### `public int `[`malloc_graym`](#mem_8h_1a467c8f80c6e9b5e5edde9bb95e9e0813)`(int imW,int imH,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` *** _im,char clr)` 

#### `public int `[`malloc_pixelm`](#mem_8h_1a5af49b10bcac51b8bee89d137094911b)`(int imW,int imH,`[`pixel`](#mem_8h_1a8d2cd65144e7fb3db3b92889edeb1904)` *** _im,char clr)` 

#### `public int `[`malloc_I1m`](#mem_8h_1a114839923279fad737ba92f892a4a5e2)`(int R,int C,`[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` *** _mat,char clr)` 

#### `public int `[`malloc_F1m`](#mem_8h_1afc96f3520676803230236c84515f4ae9)`(int R,int C,`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` *** _mat,char clr)` 

#### `public int `[`malloc_D1m`](#mem_8h_1ae9ee6ca94e22c18b7d1fc71ecc8984fd)`(int R,int C,`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` *** _mat,char clr)` 

#### `public int `[`malloc_F1t`](#mem_8h_1aaf8a40c7bfea53a05814c3fc7f298881)`(int D,`[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` *** _mat,char clr)` 

#### `public int `[`malloc_D1t`](#mem_8h_1a7bbc91755cbd9ca19c451e9969d1e264)`(int D,`[`D1`](#mem_8h_1a2b1eb1f0a858719ed4fb6444cc40d791)` *** _mat,char clr)` 

#### `public void `[`nullfree`](#mem_8h_1a6aebb3bdc6c6c84d19e7938cdda52f28)`(void * ptr)` 

#### `public int `[`mclone`](#mem_8h_1af8c488b80769c8ca4860d995b4d45ed6)`(char ** mat,int R,int C,int size,char *** _clon)` 

#### `public int `[`mem`](#mem_8h_1ac1447d2f2eb5ed26ed86ac81bbbde0f5)`(int size,char clr,char ** _p)` 

#### `public int `[`mmem`](#mem_8h_1aba14ccbeca39769f8e14d99ba73bd1bb)`(int R,int C,int size,char clr,char *** _mat)` 

#### `public int `[`bmem`](#mem_8h_1aaeca8c0eda4783d3da8f11e8e952c52e)`(int R,int C,int size,char clr,int brd,char *** _mat)` 

#### `public int `[`tmem`](#mem_8h_1a66f4d65fa18163eeafed4deb2865e1c0)`(int D,int size,char clr,char *** _mat)` 

#### `public void `[`vrmem_index`](#mem_8h_1a5abb4274279b20e09acbb986f8a570c4)`(int size,int * R,int C,char ** mat)` 

#### `public int `[`vrmem`](#mem_8h_1aa410e5fb6c64b8dfdd17cadf346f82aa)`(int size,int tnnz,int * R,int C,char clr,char *** _mat,int ** _R)` 

#### `public regex `[`reXheight`](#_page_x_m_l_8cc_1a726c6cc001ee5d420a795decf8fd680d)`(".*x-height: *([0-9.]+) *px;.*")` 

#### `public regex `[`reRotation`](#_page_x_m_l_8cc_1ace361379b17a512eaf8ef91bc8ee0914)`(".*readingOrientation: *([0-9.]+) *;.*")` 

#### `public regex `[`reDirection`](#_page_x_m_l_8cc_1a3eab4de6fb9cae3e28f0fc041a4da1cb)`(".*readingDirection: *([lrt]t[rlb]) *;.*")` 

#### `public regex `[`reFileExt`](#_page_x_m_l_8cc_1ad5282dbd2e59128edd3d72ba918edaac)`("\")` 

#### `public regex `[`reInvalidBaseChars`](#_page_x_m_l_8cc_1aa7ad44cbc1ef82ed4fcadaec999ed6ad)`(" ")` 

#### `public regex `[`reImagePageNum`](#_page_x_m_l_8cc_1a4714abac484a975e267fc6c240351a20)`("(.*)\0-9]+)\)` 

#### `public regex `[`reIsPdf`](#_page_x_m_l_8cc_1ac72179235a1c7e62570ea65b1055be4c)`(".+\f(\-9]+\0,1}$",std::regex::icase)` 

#### `public regex `[`reIsTiff`](#_page_x_m_l_8cc_1a192ae590965b3d04d774f30aff3088bd)`(".+\f{1,2}(\-9]+\0,1}$",std::regex::icase)` 

#### `public static void `[`validationErrorFunc`](#_page_x_m_l_8cc_1a42193d6b48be67e3479f98616552874c)`(void *ctx  __attribute__,const char * msg,...)` 

Schema validation ///.

#### `public static void `[`validationWarningFunc`](#_page_x_m_l_8cc_1a4a5264df828c064fb9d585c736895e78)`(void *ctx  __attribute__,const char * msg,...)` 

#### `public void `[`mktemp`](#_page_x_m_l_8cc_1a54bdec4c6dd5a11b008fc79598dfbd64)`(const char * tempbase,char * tempname)` 

Function that creates a temporal file using the mktemp command

#### Parameters
* `tempbase` The mktemp template to use, including at least 3 consecutive X.

#### `public static std::vector< double > `[`project_2d_to_1d`](#_page_x_m_l_8cc_1aa295be52a9f7d03cb5a745bc6b2550e9)`(std::vector< cv::Point2f > points,cv::Point2f axis,double yoffset)` 

Projects points onto a line defined by a direction and y-offset

#### `public inline static double `[`angleDiff`](#_page_x_m_l_8cc_1a61fc06d078d73deb50298f47d612eedd)`(double a1,double a2)` 

Computes the difference between two angles [-PI,PI] accounting for the discontinuity

#### `public inline static double `[`intersection_1d`](#_page_x_m_l_8cc_1a8cb2d5f6e60399cf47f11bb9201fb4dc)`(double & a1,double & a2,double & b1,double & b2)` 

Computes the 1D intersection

#### `public inline static double `[`IoU_1d`](#_page_x_m_l_8cc_1ac09c1ca85100d59d39f77e7f545eca8d)`(double a1,double a2,double b1,double b2)` 

Computes the 1D intersection over union

#### `public double `[`withinSegment`](#_page_x_m_l_8cc_1a01aee68a0af5ee992c2f6b499b4a5558)`(cv::Point2f segm_start,cv::Point2f segm_end,cv::Point2f point)` 

Checks if a point is within a line segment

#### Parameters
* `segm_start` Point for begining of segment. 

* `segm_end` Point for end of segment. 

* `point` Point to check withiness. 

#### Returns
0 if within segment, +1 if outside but aligned to the right, -1 if outside but aligned to the left, otherwise NaN.

#### `public const Magick::Color `[`colorWhite`](#_text_feat_extractor_8cc_1a1c101d5ae529d47ee2630004d33ed452)`("white")` 

#### `public const Magick::Color `[`colorBlack`](#_text_feat_extractor_8cc_1a52730ed7e5affa8a15f42e952281b0f5)`("black")` 

#### `public inline static void `[`print_int`](#_text_feat_extractor_8cc_1ac53eacb3014c40030f7474620c78fbac)`(long data,FILE * file)` 

Loaders ///.

Loads the projecton matrix from an hdf5 file.

#### Parameters
* `projfile` File from which to read the projection.Features output /// Prints a long in binary.

#### `public inline static void `[`print_short`](#_text_feat_extractor_8cc_1ac814fb690cd4494501cc3de16c920276)`(int data,FILE * file)` 

Prints an int in binary.

#### `public inline static void `[`print_float`](#_text_feat_extractor_8cc_1a2dbcb88814027a8aec1d924775a57737)`(float data,FILE * file)` 

Prints a float in binary.

#### `public static void `[`print_features_htk`](#_text_feat_extractor_8cc_1a521b3512933909ece7bd18cf625ad5fe)`(const cv::Mat & feats,FILE * file)` 

Prints features to a file stream using HTK format.

#### Parameters
* `feats` OpenCV matrix containing the features. 

* `file` File stream to print the features.

#### `public static void `[`print_features_ascii`](#_text_feat_extractor_8cc_1ae3a1fa6530381f534ec5e2ff90495b8e)`(const cv::Mat & feats,FILE * file)` 

Prints features to a file stream using ASCII format.

#### Parameters
* `feats` OpenCV matrix containing the features. 

* `file` File stream to print the features.

#### `public static void `[`magick2cvmat8u`](#_text_feat_extractor_8cc_1ac0d8f9ed183c953d3ced538c9f1ce002)`(Magick::Image & image,cv::Mat & cvimg)` 

Image processing ///.

Copies image data from Magick::Image to an OpenCV Mat.

#### Parameters
* `image` Magick++ Image object. 

* `cvimg` OpenCV Mat.

#### `public static void `[`magick2cvmat8uc3`](#_text_feat_extractor_8cc_1abd4530acf52f35d5ba38b9f3038b0ab1)`(Magick::Image & image,cv::Mat & cvimg)` 

Copies image data from Magick::Image to an OpenCV Mat.

#### Parameters
* `image` Magick++ Image object. 

* `cvimg` OpenCV Mat.

#### `public static void `[`magick2graym`](#_text_feat_extractor_8cc_1a3033920ea2862f45dfd32ec026fa8088)`(Magick::Image & image,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` **& gimg,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` *** _alpha)` 

Copies image data from Magick::Image to an unsigned char matrix.

#### Parameters
* `image` Magick++ Image object. 

* `gimg` Unsigned char matrix (it is allocated if NULL). 

* `_alpha` Pointer to unsigned char matrix for alpha channel (it is allocated if NULL).

#### `public inline static int `[`to16bits`](#_text_feat_extractor_8cc_1a1a811eaff5dda86d249594fe3d992259)`(int val)` 

Converts unsigned char to 16-bits.

#### `public static void `[`graym2magick`](#_text_feat_extractor_8cc_1a3d05d264e460dccb52ae7b0512f658f1)`(Magick::Image & image,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** gimg,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alpha)` 

Copies image data from unsigned char matrix to Magick::Image.

#### Parameters
* `image` Magick++ Image object. 

* `gimg` Unsigned char matrix. 

* `alpha` Unsigned char matrix for alpha channel.

#### `public static void `[`grayms2magick`](#_text_feat_extractor_8cc_1a066bfd0260bf6e3dd2ec159f26dfc9c3)`(Magick::Image & image,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** rimg,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** gimg,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** bimg,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** alpha)` 

Copies image data from unsigned char matrix to Magick::Image.

#### Parameters
* `image` Magick++ Image object. 

* `rimg` Unsigned char matrix of read channel. 

* `gimg` Unsigned char matrix of green channel. 

* `bimg` Unsigned char matrix of blue channel. 

* `alpha` Unsigned char matrix of alpha channel.

#### `public static void `[`cvmat8u2magick`](#_text_feat_extractor_8cc_1af1756b455bc263fea7aadde3a4e847ae)`(Magick::Image & image,cv::Mat & cvimg)` 

Copies image data from an OpenCV Mat to Magick::Image.

#### Parameters
* `image` Magick++ Image object. 

* `cvimg` OpenCV Mat.

#### `public static void `[`cvmat8uc32magick`](#_text_feat_extractor_8cc_1a1bb4e2cb8ba2fa857e784c0dfb6a3761)`(Magick::Image & image,cv::Mat & cvimg)` 

Copies image data from an OpenCV Mat to Magick::Image.

#### Parameters
* `image` Magick++ Image object. 

* `cvimg` OpenCV Mat.

#### `public static void `[`cvmat8u2magick`](#_text_feat_extractor_8cc_1accdc54fbd584e586cad5bbdb08035659)`(Magick::Image & image,cv::Mat & cvimg,cv::Mat & cvimg_alpha)` 

Copies image data from an OpenCV Mat to Magick::Image.

#### Parameters
* `image` Magick++ Image object. 

* `cvimg` OpenCV Mat. 

* `cvimg_alpha` OpenCV Mat.

#### `public static void `[`enhance`](#_text_feat_extractor_8cc_1a81f14f6e96fbff1e6d74739c0c93f358)`(Magick::Image & image,int winW,double prm1,double slp,int type,double prm0,double prm2)` 

Does a local enhancement of a text image.

#### Parameters
* `image` Magick++ Image object. 

* `winW` Window width for local enhancement. 

* `prm1` Enhancement parameter. 

* `slp` Gray slope parameter. 

* `type` Enhancement algorithm. 

* `prm0` Enhancement parameter to store in channel 0 (set to 0.0 for single channel output). 

* `prm2` Enhancement parameter to store in channel 2 (set to 0.0 for single channel output).

#### `public int `[`rlsa4_graym`](#_text_feat_extractor_8cc_1a3b1901a411f56afa5aad0b3fe0d5b5f0)`(`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** img,int imgW,int imgH,char op,int * lengths,bool negate,`[`gray`](#mem_8h_1ab4acb9d5bd7df088fccd3055f89b8279)` ** res)` 

Four directional RLSA algorithm.

#### Parameters
* `img` Unsigned char matrix of input image. 

* `imgW` Image width. 

* `imgH` Image height. 

* `op` Directions enabled (bit0 '-', bit1 '|', bit2 '/', bit3 '\'). 

* `lengths` RLSA lengths for each direction. 

* `negate` Whether to negate imput. 

* `res` Unsigned char matrix of output image.

#### `public inline static void `[`findMinMax`](#_text_feat_extractor_8cc_1a83ec3f37e202c24e48620142056dd6ab)`(int size,double * vals,bool * isset,double * _minval,double * _maxval,int * _minidx,int * _maxidx)` 

#### `public static double `[`estimateSlant`](#_text_feat_extractor_8cc_1af850a209ee624d37c3f427125a67f80e)`(Magick::Image & image,double amin,double amax,double astep,int hsteps,double hfact)` 

Estimates the slant angle of an image containing handwritten text.

#### Parameters
* `image` Magick++ Image object. 

* `amin` Minimum slant angle in degrees. 

* `amax` Maximum slant angle in degrees. 

* `amin` Slant angle step in degrees. 

#### Returns
Estimated slant angle in degrees.

> Todo: If alpha channel, do not project transparent

#### `public void `[`findOuterContours`](#_text_feat_extractor_8cc_1af7639c4a00fe54f47a88eef066ef1a0b)`(Magick::Image & img,vector< vector< cv::Point > > & contours,int method,double eps)` 

Gets outer contour points of connected components in an image, optionally approximating it.

#### Parameters
* `image` Magick++ Image object. 

* `contours` Output array of arrays containing the contours. 

* `method` Contour approximation method. 

* `eps` Epsilon for approxPolyDP, zero to disable.

#### `public static void `[`joinComponents`](#_text_feat_extractor_8cc_1a4da782c15ab0baee562d0370e6297e02)`(Magick::Image & img)` 

Joints all connected components in an image using 1px thick lines between nearest contour points.

#### Parameters
* `image` Magick++ Image object.

#### `public bool `[`toGrayscale`](#_text_feat_extractor_8cc_1a360080636b9ecf83ebbf859d652ffedc)`(cv::Mat & image,cv::Mat & image_alpha)` 

Converts image to grayscale preserving alpha channel if present.

#### Parameters
* `image` Image to process. 

#### Returns
Whether the conversion was performed.

#### `public bool `[`flattenImage`](#_text_feat_extractor_8cc_1ab109c954f49e5729f8adc65382209b34)`(Magick::Image & image,const Magick::Color * color)` 

Removes alpha channel, setting all transparent regions to the background color.

#### Parameters
* `image` Image to process. 

* `color` Color for the background. 

#### Returns
Whether flattening was performed.

# class `OGRMultiLineString_` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public OGRMultiLineString * `[`multipolyline`](#class_o_g_r_multi_line_string___1a591b8a564dfa78aaf8fb9f091c1f3e84) | 
`public  `[`~OGRMultiLineString_`](#class_o_g_r_multi_line_string___1a4cb34985e906b72407172328e7ac6103)`()` | 
`public  `[`OGRMultiLineString_`](#class_o_g_r_multi_line_string___1a4212f1b78f3426208e11a4adc2c0fb77)`()` | 
`public  `[`OGRMultiLineString_`](#class_o_g_r_multi_line_string___1af6a7b543a4e76216a60964f276213384)`(OGRGeometry * geometry)` | 

## Members

#### `public OGRMultiLineString * `[`multipolyline`](#class_o_g_r_multi_line_string___1a591b8a564dfa78aaf8fb9f091c1f3e84) 

#### `public  `[`~OGRMultiLineString_`](#class_o_g_r_multi_line_string___1a4cb34985e906b72407172328e7ac6103)`()` 

#### `public  `[`OGRMultiLineString_`](#class_o_g_r_multi_line_string___1a4212f1b78f3426208e11a4adc2c0fb77)`()` 

#### `public  `[`OGRMultiLineString_`](#class_o_g_r_multi_line_string___1af6a7b543a4e76216a60964f276213384)`(OGRGeometry * geometry)` 

# class `OGRMultiPolygon_` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public OGRMultiPolygon * `[`multipolygon`](#class_o_g_r_multi_polygon___1a0594033824c664ed647e18a3d9b79083) | 
`public  `[`~OGRMultiPolygon_`](#class_o_g_r_multi_polygon___1ad083a2dc271aab3ceba7a0836e4b9df9)`()` | 
`public  `[`OGRMultiPolygon_`](#class_o_g_r_multi_polygon___1a62f54d49e43abe6ce938217104aadb1b)`()` | 
`public  `[`OGRMultiPolygon_`](#class_o_g_r_multi_polygon___1a8baa6eb516212b6f101709bcea50a6bd)`(OGRGeometry * geometry)` | 

## Members

#### `public OGRMultiPolygon * `[`multipolygon`](#class_o_g_r_multi_polygon___1a0594033824c664ed647e18a3d9b79083) 

#### `public  `[`~OGRMultiPolygon_`](#class_o_g_r_multi_polygon___1ad083a2dc271aab3ceba7a0836e4b9df9)`()` 

#### `public  `[`OGRMultiPolygon_`](#class_o_g_r_multi_polygon___1a62f54d49e43abe6ce938217104aadb1b)`()` 

#### `public  `[`OGRMultiPolygon_`](#class_o_g_r_multi_polygon___1a8baa6eb516212b6f101709bcea50a6bd)`(OGRGeometry * geometry)` 

# class `PageXML` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`~PageXML`](#class_page_x_m_l_1accc94a5c0375b71fd2f058abc04ca25e)`()` | [PageXML](#class_page_x_m_l) object destructor.
`public  `[`PageXML`](#class_page_x_m_l_1a0b930b74d48fe26bdfbfee7cde0df960)`(const char * pagexml_path,const char * schema_path)` | Constructors ///.
`public void `[`loadSchema`](#class_page_x_m_l_1a26f73cb3afd642889c5c6e7e5bd4a2ba)`(const char * schema_path)` | Loads a schema for xml validation.
`public bool `[`isValid`](#class_page_x_m_l_1a3ae4157e63f4252bae130e20f63181f7)`()` | Validates the currently loaded XML.
`public void `[`printConf`](#class_page_x_m_l_1a2f243e564f59e0e86be34fb3641526e0)`(FILE * file)` | Configuration ///.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`newXml`](#class_page_x_m_l_1a95f40947e6da8415578a4dcaf7a8eea3)`(const char * creator,const char * image,const int imgW,const int imgH)` | Loaders ///.
`public void `[`loadXml`](#class_page_x_m_l_1a4ec7578dd9794ac300d9bbf1e04d6f55)`(const char * fname,bool validate)` | Loads a Page XML from a file.
`public void `[`loadXml`](#class_page_x_m_l_1a803d631c80ea3cc9d93b03a791fb560c)`(int fnum,bool prevfree,bool validate)` | Loads a Page XML from an input stream.
`public void `[`loadXmlString`](#class_page_x_m_l_1a70b4da88ce7f75a92fc3127e7b7e5c1f)`(const char * xml_string,bool validate)` | Loads a Page XML from a string.
`public void `[`releaseImage`](#class_page_x_m_l_1a42af7ec35f05910aa3fa322f053240be)`(int pagenum)` | Releases an already loaded image.
`public void `[`releaseImage`](#class_page_x_m_l_1a7ae389bfa05769d488568131fa4a49fd)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | 
`public void `[`releaseImages`](#class_page_x_m_l_1ae8f1b698bf3abeee79a84d79dc877b7d)`()` | 
`public void `[`loadImage`](#class_page_x_m_l_1acc541aed93c06fdfeec29ad217f217a8)`(int pagenum,const char * fname,const bool resize_coords,int density)` | 
`public void `[`loadImage`](#class_page_x_m_l_1a74593bb0b4ca5e266dfc5650ca5009d0)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * fname,const bool resize_coords,int density)` | 
`public void `[`loadImages`](#class_page_x_m_l_1a21450ed106a7a385b9b391b6cb033d4c)`(const bool resize_coords,const int density)` | 
`public int `[`simplifyIDs`](#class_page_x_m_l_1a5d3b4a59cecbf6fdf8c84f806a7648f0)`()` | Simplifies IDs by removing imgbase prefixes and replaces invalid characters with _.
`public void `[`relativizeImageFilename`](#class_page_x_m_l_1a3c43349d7cff78cea6d1ba7b01f023b3)`(const char * xml_path)` | Modifies imageFilename to be a relative path w.r.t. given xml path. Currently just checks prefix directories and removes it.
`public std::vector< std::string > `[`getImageBases`](#class_page_x_m_l_1a3c43f4e51877f674f29af7a421fa973b)`()` | Gets image bases for all pages in xml.
`public bool `[`areIDsUnique`](#class_page_x_m_l_1aeb8f1e60e4e2521c2bb50fe495327648)`()` | Verifies that all IDs in page are unique.
`public std::string `[`getNodeName`](#class_page_x_m_l_1a8e8ded73daa9edf93b02d75bac16b9de)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` base_node)` | Gets the name of the given node.
`public std::vector< `[`NamedImage`](#struct_named_image)` > `[`crop`](#class_page_x_m_l_1a3264214ef4bc3ea7d5706b33440c57a0)`(const char * xpath,cv::Point2f * margin,bool opaque_coords,const char * transp_xpath,const char * base_xpath)` | Crops images using its Coords polygon, regions outside the polygon are set to transparent.
`public int `[`count`](#class_page_x_m_l_1a4e96a80a41b38f74a9328eab24ed11a0)`(const char * xpath,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Returns number of matched nodes for a given xpath.
`public int `[`count`](#class_page_x_m_l_1a5817463d6e13c9472d1995e964ce28a7)`(std::string xpath,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | 
`public std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > `[`select`](#class_page_x_m_l_1a33d04b764e3a0c853ef7de78ca78cd41)`(const char * xpath,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Selects nodes given an xpath.
`public std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > `[`select`](#class_page_x_m_l_1ad1fd441a90b31c4900bb9896185a177f)`(std::string xpath,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | 
`public std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > `[`select`](#class_page_x_m_l_1a6207c5d079018e4daff6de195ddf0512)`(const char * xpath,const std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > nodes,bool unique)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`selectNth`](#class_page_x_m_l_1a693a2275353703a06ae90427d59e416e)`(const char * xpath,int num,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Selects the n-th node that matches an xpath.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`selectNth`](#class_page_x_m_l_1ae29d8b0b92240bc0866064c88c1eb0ab)`(std::string xpath,int num,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`selectByID`](#class_page_x_m_l_1ace787087add3c5f3016ec837553d48b5)`(const char * id,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Selects an element with a given ID.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`closest`](#class_page_x_m_l_1a089e2ca706141bf750b301fd34595fc1)`(const char * name,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Selects closest node of a given name.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`parent`](#class_page_x_m_l_1a8ac32174f32b120caf595ec3a82e57d1)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Returns the parent of a node.
`public std::string `[`getValue`](#class_page_x_m_l_1a806731e1825cfbfa406ddf3e6978d747)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Retrieves a node value.
`public std::string `[`getValue`](#class_page_x_m_l_1ae27ba3fb4d85e0ba2cee85125a6eaa54)`(const char * xpath,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Retrieves a node value.
`public void `[`setValue`](#class_page_x_m_l_1a67163afa48565eafd017cb134a324e6b)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * value)` | Sets a node value.
`public std::string `[`getAttr`](#class_page_x_m_l_1a23e16f7c70950b4fe990b8c22a2e1ce5)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * name)` | Gets an attribute value from an xml node.
`public std::string `[`getAttr`](#class_page_x_m_l_1abef00c0a3b59143989b8d29beaeb14bf)`(const char * xpath,const char * name)` | Gets an attribute value for a given xpath.
`public std::string `[`getAttr`](#class_page_x_m_l_1a057bb3cecf33b3cd2e621d56095a4716)`(const std::string xpath,const std::string name)` | 
`public int `[`setAttr`](#class_page_x_m_l_1ada5a3f0e91615340782afe1eea87c23d)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > nodes,const char * name,const char * value)` | 
`public int `[`setAttr`](#class_page_x_m_l_1abaa5b2ad59b0769bb8cff58a53b04231)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * name,const char * value)` | Adds or modifies (if already exists) an attribute for a given node.
`public int `[`setAttr`](#class_page_x_m_l_1a8cc6e9bffff7951aa5db47af47642601)`(const char * xpath,const char * name,const char * value)` | Adds or modifies (if already exists) an attribute for a given xpath.
`public int `[`setAttr`](#class_page_x_m_l_1a8d1d681d5b986527265ff07c757a2b3b)`(const std::string xpath,const std::string name,const std::string value)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`insertElem`](#class_page_x_m_l_1ab0e8796f7920a2fc3ff1a490b85b6b8b)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype)` | Inserts an element relative to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addElem`](#class_page_x_m_l_1a2dd9a0a6cfeb68a91c005740dd6ce315)`(const char * name,const char * id,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype,bool checkid)` | Creates a new element and adds it relative to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addElem`](#class_page_x_m_l_1a4b218c9cddda9763bdd3f65d3074d5f7)`(const char * name,const char * id,const char * xpath,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype,bool checkid)` | Creates a new element and adds it relative to a given xpath.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addElem`](#class_page_x_m_l_1abbbf302357d6016ffde3a2b859fa1f93)`(const std::string name,const std::string id,const std::string xpath,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype,bool checkid)` | 
`public void `[`rmElem`](#class_page_x_m_l_1ad3e1cc3040a7aef670d64fac0e2e82d8)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Removes the given element.
`public int `[`rmElems`](#class_page_x_m_l_1a58b3870ad811accb8b91a433796fbf6f)`(const std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > & nodes)` | 
`public int `[`rmElems`](#class_page_x_m_l_1a615f87470132c8b50200e86492ffdf4c)`(const char * xpath,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Remove the elements that match a given xpath.
`public int `[`rmElems`](#class_page_x_m_l_1a1a47165a43b3de66729400c9a318c180)`(const std::string xpath,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`copyElem`](#class_page_x_m_l_1a40dc146d23d3e146ce2332764b1e913a)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype)` | Clone an element and add it relative to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`moveElem`](#class_page_x_m_l_1af214054f7b648086704f7cc0bd3b51e1)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype)` | Unlink an element and add it relative to a given node.
`public int `[`moveElems`](#class_page_x_m_l_1ac6320b747e78baa3d2f5753086e54189)`(const std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > & elems,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype)` | Unlink elements and add them relative to a given node.
`public void `[`setRotation`](#class_page_x_m_l_1afc92cad64293df78c84bc7d8c899cf6f)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem,const float rotation)` | Sets the rotation angle to a TextRegion node.
`public void `[`setReadingDirection`](#class_page_x_m_l_1af1eef0ce8e1ff941b79430db6802e51a)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem,`[`PAGEXML_READ_DIRECTION`](#_page_x_m_l_8h_1a151afb8ef7c7e05585713fafd180a2ea)` direction)` | Sets the reading direction to a TextRegion node.
`public double `[`getDominantBaselinesOrientation`](#class_page_x_m_l_1ace699f89ee2dedc3304b2a7acf2c5135)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > elems)` | Gets the dominant orientation angle for a set of baselines.
`public double `[`getBaselineOrientation`](#class_page_x_m_l_1a01d20d4333c5011f80bf83fe246ac76b)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem)` | Gets the baseline orientation angle (weighted average over polyline segments) of a given text line.
`public double `[`getPolylineOrientation`](#class_page_x_m_l_1a3b765fd1a88f7c36eac75b68e87dd010)`(std::vector< cv::Point2f > points)` | Gets the baseline orientation angle (weighted average over polyline segments) in radians of a given baseline.
`public double `[`getPolylineLength`](#class_page_x_m_l_1a234aa0cc97d29a247cc4b6f08d912206)`(std::vector< cv::Point2f > points)` | Gets the baseline length.
`public double `[`getRotation`](#class_page_x_m_l_1a6e68136a69dd82168bbc28c64bff45e4)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem)` | Retrieves the rotation angle for a given TextLine or TextRegion node.
`public int `[`getReadingDirection`](#class_page_x_m_l_1acc2adc9d4408836ea87d8056e2d522f6)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem)` | Retrieves the reading direction for a given TextLine or TextRegion node.
`public float `[`getXheight`](#class_page_x_m_l_1a6d7cd4ada93f19226e3723d6c41a9ebf)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Retrieves the x-height for a given TextLine node.
`public float `[`getXheight`](#class_page_x_m_l_1a401b8196ba181dec3fa5d76eb9c6e585)`(const char * id)` | Retrieves the x-height for a given TextLine id.
`public std::vector< cv::Point2f > `[`getFpgram`](#class_page_x_m_l_1a0425df4d97b66a7f259cfb1fae847667)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Retrieves the features parallelogram (Property[="fpgram"]/) for a given node.
`public std::vector< cv::Point2f > `[`getPoints`](#class_page_x_m_l_1aba7be6cf9e66f1395c84f0880ca2a069)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * xpath)` | Retrieves and parses the Coords/ for a given base node.
`public std::vector< std::vector< cv::Point2f > > `[`getPoints`](#class_page_x_m_l_1a41e062ef2c08e4c3212c39d4ec48b2fa)`(const std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > nodes,const char * xpath)` | Retrieves and parses the Coords/ for a given list of base nodes.
`public std::string `[`getTextEquiv`](#class_page_x_m_l_1a00ab0efcf9edb0224208962c807e465f)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * xpath,const char * separator)` | Retrieves the concatenated TextEquivs for a given root node and xpath.
`public void `[`processStart`](#class_page_x_m_l_1a3eeffa37a2ace0dc732405e81cb49e4d)`(const char * tool,const char * ref)` | Starts a process in the Page XML.
`public void `[`processEnd`](#class_page_x_m_l_1a29d780f46c1f14b241f48665d835394c)`()` | Ends the running process in the Page XML.
`public void `[`updateLastChange`](#class_page_x_m_l_1a99bc8c45fae21207bb608e69609dedcd)`()` | Updates the last change time stamp.
`public std::string `[`getPropertyValue`](#class_page_x_m_l_1ab4d79c28bc94086d1d379f0ea73ff899)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * key)` | Retrieves a Property value.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setProperty`](#class_page_x_m_l_1af6e80d30313f63054228fcb15305db31)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * key,const char * val,const double * _conf)` | Sets a Property to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setProperty`](#class_page_x_m_l_1aa05ac4ccd18740e84e8566f5f07ed876)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * key,const char * val,const double conf)` | Sets a Property to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setProperty`](#class_page_x_m_l_1a82ffe7a5366736034a3e4514b43ab389)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * key,const double val,const double * _conf)` | Sets a Property to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setProperty`](#class_page_x_m_l_1a8acc4a27f30da3f3d75c93baf5280a6d)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * key,const double val,const double conf)` | Sets a Property to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setTextEquiv`](#class_page_x_m_l_1a65f380acfc400de2a6dc59eb1ee22904)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * text,const double * _conf)` | Adds or modifies (if already exists) the TextEquiv for a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setTextEquiv`](#class_page_x_m_l_1a3d01bccae1af691fc5cc60e720d1659b)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * text,const double conf)` | Adds or modifies (if already exists) the TextEquiv for a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setTextEquiv`](#class_page_x_m_l_1ae7938084955a0668bc44f24307ad77ba)`(const char * xpath,const char * text,const double * _conf)` | Adds or modifies (if already exists) the TextEquiv for a given xpath.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setTextEquiv`](#class_page_x_m_l_1aeaad48fa1ad577caa032534960e955f0)`(const char * xpath,const char * text,const double conf)` | Adds or modifies (if already exists) the TextEquiv for a given xpath.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoords`](#class_page_x_m_l_1a8d92328ba656b8e8e847bf2ad3607a46)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const std::vector< cv::Point2f > & points,const double * _conf)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoords`](#class_page_x_m_l_1acf4d9ee3ef34fc928e4b3b0e53221284)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const std::vector< cv::Point2f > & points,const double conf)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoords`](#class_page_x_m_l_1a626847a8aac3c4bc650d0b27f3ce042b)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const std::vector< cv::Point > & points,const double * _conf)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoords`](#class_page_x_m_l_1a65dd07db2a1b0babba52c5d3423557e6)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const std::vector< cv::Point > & points,const double conf)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoords`](#class_page_x_m_l_1a1038c674a0522759ea3004bac9cac5f2)`(const char * xpath,const std::vector< cv::Point2f > & points,const double * _conf)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoords`](#class_page_x_m_l_1afbbded5bbdd2b5716782604aa5b22297)`(const char * xpath,const std::vector< cv::Point2f > & points,const double conf)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoordsBBox`](#class_page_x_m_l_1ac42051db4e4f1feb754401e78f5cb53d)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,double xmin,double ymin,double width,double height,const double * _conf,bool subone)` | Adds or modifies (if already exists) the Coords as a bounding box for a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoordsBBox`](#class_page_x_m_l_1a2e4028e182c73058112b3d1009925c65)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,double xmin,double ymin,double width,double height,const double conf,bool subone)` | Adds or modifies (if already exists) the Coords as a bounding box for a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setBaseline`](#class_page_x_m_l_1a2a85dc0b7eb35ac29780551a642a3e51)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const std::vector< cv::Point2f > & points,const double * _conf)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setBaseline`](#class_page_x_m_l_1a0d9eaff78f737a19fafe17b09c6b87fd)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const std::vector< cv::Point2f > & points,const double conf)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setBaseline`](#class_page_x_m_l_1a12a577c21cf6109f30843336bbdaba8d)`(const char * xpath,const std::vector< cv::Point2f > & points,const double * _conf)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setBaseline`](#class_page_x_m_l_1a9b2b8f89080a44663008d011c118801c)`(const char * xpath,const std::vector< cv::Point2f > & points,const double conf)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setBaseline`](#class_page_x_m_l_1a489cf14031d07454f538a048e4b48c03)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,double x1,double y1,double x2,double y2,const double * _conf)` | Adds or modifies (if already exists) a two point Baseline for a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setBaseline`](#class_page_x_m_l_1af8a1bedc13b1c70a7bb6f249b8e34f52)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,double x1,double y1,double x2,double y2,const double conf)` | Adds or modifies (if already exists) a two point Baseline for a given node.
`public bool `[`intersection`](#class_page_x_m_l_1a37da0ed1fb708b374e7d83e6b22cbb23)`(cv::Point2f line1_point1,cv::Point2f line1_point2,cv::Point2f line2_point1,cv::Point2f line2_point2,cv::Point2f & _ipoint)` | Finds the intersection point between two lines defined by pairs of points or returns false if no intersection
`public bool `[`isPolystripe`](#class_page_x_m_l_1a61c1b6597c7bcf7b65dc195e95ef7ab4)`(std::vector< cv::Point2f > coords,std::vector< cv::Point2f > baseline,double * height,double * offset)` | Checks whether Coords is a poly-stripe for its corresponding baseline.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setPolystripe`](#class_page_x_m_l_1ab97470a0132a3e497c80f26e061aba28)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,double height,double offset,bool offset_check)` | Sets the Coords of a TextLine as a poly-stripe of the baseline.
`public int `[`getPageNumber`](#class_page_x_m_l_1ae660a692143a9983406bba434037e78c)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Gets the page number for the given node.
`public void `[`setPageImageOrientation`](#class_page_x_m_l_1a7f89e6da35429f37f6d887b36510772c)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,int angle,const double * _conf)` | Sets the image orientation for the given Page node.
`public void `[`setPageImageOrientation`](#class_page_x_m_l_1ae2e91ca140cb87bd3fe4420fcab890fe)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,int angle,const double conf)` | Sets the image orientation for the given Page node.
`public void `[`setPageImageOrientation`](#class_page_x_m_l_1a94c03640c38f7ddd743b9c0423c71342)`(int pagenum,int angle,const double * _conf)` | Sets the image orientation for the given Page number.
`public void `[`setPageImageOrientation`](#class_page_x_m_l_1ab08bc018507912fef86910f9f4822551)`(int pagenum,int angle,const double conf)` | Sets the image orientation for the given Page number.
`public int `[`getPageImageOrientation`](#class_page_x_m_l_1a3f776930d7d1be6239497c49f6ea6b9a)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Gets the image orientation for the given node.
`public int `[`getPageImageOrientation`](#class_page_x_m_l_1acd1a1b7bbe14a6c8e14e3ef5afccd3cf)`(int pagenum)` | Gets the image orientation for the given Page number.
`public unsigned int `[`getPageWidth`](#class_page_x_m_l_1a7746613d3800267f27d7bef2240ec827)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Gets the width of a page (might be different to image width due to the image orientation).
`public unsigned int `[`getPageWidth`](#class_page_x_m_l_1aa1b7155d7ae5b37710310b7891d1c314)`(int pagenum)` | Gets the width of a page (might be different to image width due to the image orientation).
`public unsigned int `[`getPageHeight`](#class_page_x_m_l_1ab96562c1fe4d95706778507ed2e8b57d)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Gets the height of a page (might be different to image width due to the image orientation).
`public unsigned int `[`getPageHeight`](#class_page_x_m_l_1a80e90205b325157f3d1fd680f7ebc108)`(int pagenum)` | Gets the height of a page (might be different to image width due to the image orientation).
`public void `[`setPageWidth`](#class_page_x_m_l_1a4887c81a8f839015ff4643ba09193355)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,int width)` | Sets the width of a page (actually sets imageWidth accounting for image orientation).
`public void `[`setPageHeight`](#class_page_x_m_l_1acdd80beebd7ba3a38459ad46e103761e)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,int height)` | Sets the height of a page (actually sets imageHeight accounting for image orientation).
`public std::vector< cv::Size2i > `[`getPagesSize`](#class_page_x_m_l_1a525354fa982782061b40718607b960dd)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > pages)` | Retrieves pages size.
`public std::vector< cv::Size2i > `[`getPagesSize`](#class_page_x_m_l_1aab0456c928c85b694387acf75339c02f)`(const char * xpath)` | Retrieves pages size.
`public int `[`rotatePage`](#class_page_x_m_l_1a66d218878c54780c72ec9edda4b1d72e)`(int angle,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` page,bool update_image_orientation,const double conf)` | Rotates a page.
`public int `[`rotatePage`](#class_page_x_m_l_1afd756366f58bb47b0f1961fce3dcbe71)`(int angle,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` page,bool update_image_orientation,const double * _conf)` | Rotates a page.
`public int `[`resize`](#class_page_x_m_l_1a81f6aa2af3574985f268959662ac4c2b)`(std::vector< cv::Size2i > sizes,std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > pages,bool check_aspect_ratio)` | Resizes pages and all respective coordinates.
`public int `[`resize`](#class_page_x_m_l_1a8b24748e08ccb010eb709a9d91c711cc)`(std::vector< cv::Size2i > sizes,const char * xpath,bool check_aspect_ratio)` | Resizes pages and all respective coordinates.
`public int `[`resize`](#class_page_x_m_l_1ae9772185b88e2e12e26025effc2c39c7)`(cv::Size2i size,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` page,bool check_aspect_ratio)` | Resizes a page and all respective coordinates.
`public int `[`resize`](#class_page_x_m_l_1a06f171653bd8d50c03ed153523e24fc5)`(double fact,const char * xpath)` | Resizes a page and all respective coordinates.
`public void `[`setPageImageFilename`](#class_page_x_m_l_1a66d14b834c2ff1e162ddc268d92e9318)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * image)` | Sets the imageFilename of a page.
`public void `[`setPageImageFilename`](#class_page_x_m_l_1a1f6225549414316c7b42d466f37ea9ae)`(int pagenum,const char * image)` | 
`public std::string `[`getPageImageFilename`](#class_page_x_m_l_1ab6670ff942eeb850d64cb87a9932be58)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Returns the imageFilename of a page.
`public std::string `[`getPageImageFilename`](#class_page_x_m_l_1ac6fe17760af6634bf781b82831f6145b)`(int pagenum)` | 
`public bool `[`isPageImageLoaded`](#class_page_x_m_l_1a5c2c180d3f973cccf9c2a19ce2966d54)`(int pagenum)` | Checks whether a page image is loaded.
`public bool `[`isPageImageLoaded`](#class_page_x_m_l_1aba6d1e7beb4eb3fb419c4f8dc625e8a3)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | 
`public `[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` `[`getPageImage`](#class_page_x_m_l_1acc09b01d19dfafb3ccd43b0099313045)`(int pagenum)` | Returns the image for the given page.
`public `[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` `[`getPageImage`](#class_page_x_m_l_1abf54fa39f33ca21661e87528136b00b6)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addGlyph`](#class_page_x_m_l_1a0814aa1518e897289014c38c441a8bf1)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * id,const char * before_id)` | Adds a Glyph to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addGlyph`](#class_page_x_m_l_1acaa1832064f9fadb99580bce37ff2a61)`(const char * xpath,const char * id,const char * before_id)` | Adds a Glyph to a given xpath.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addWord`](#class_page_x_m_l_1ab865d14cd40a7898f7612ca3e1cb507f)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * id,const char * before_id)` | Adds a Word to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addWord`](#class_page_x_m_l_1a35b83528a5e85c0f8e5fe91e6603ea7f)`(const char * xpath,const char * id,const char * before_id)` | Adds a Word to a given xpath.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addTextLine`](#class_page_x_m_l_1a990faea859827afc6ed10243f1c347fb)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * id,const char * before_id)` | Adds a TextLine to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addTextLine`](#class_page_x_m_l_1a52798d2245ba8af0afb948b31b311243)`(const char * xpath,const char * id,const char * before_id)` | Adds a TextLine to a given xpath.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addTextRegion`](#class_page_x_m_l_1af335dbda4b11ddc8078df72ffca38f7c)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * id,const char * before_id,bool prepend)` | Adds a TextRegion to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addTextRegion`](#class_page_x_m_l_1afd831d3d6a2a33cc53feae4e4c3b4662)`(const char * xpath,const char * id,const char * before_id,bool prepend)` | Adds new TextRegion to a given xpath.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addPage`](#class_page_x_m_l_1a99fbe6075faea2c881f8a5bbb2d68f0e)`(const char * image,const int imgW,const int imgH,const char * id,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` before_node)` | Adds a Page to the PcGts node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addPage`](#class_page_x_m_l_1ad7c0aed4a410245017724a7cefc40654)`(std::string image,const int imgW,const int imgH,const char * id,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` before_node)` | Adds a Page to the PcGts node.
`public int `[`write`](#class_page_x_m_l_1a0c4b94eb5f607e85d8ae27a93e571f5f)`(const char * fname,bool validate)` | Output ///.
`public std::string `[`toString`](#class_page_x_m_l_1af19593957ab5019cfa2e606d31b000e2)`(bool validate)` | Creates a string representation of the Page XML.
`public `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` `[`pointsToOGRpolygon`](#class_page_x_m_l_1a4748cef2a547bb364d5a5e0bc15ccbc7)`(std::vector< cv::Point2f > points)` | Converts Coords to an OGRMultiPolygon.
`public std::vector< `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` > `[`pointsToOGRpolygons`](#class_page_x_m_l_1a1655a09ca1b847b129db72d6b5b56d0b)`(std::vector< std::vector< cv::Point2f > > points)` | Converts Coords to OGRMultiPolygons.
`public `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` `[`getOGRpolygon`](#class_page_x_m_l_1a3e9e0aa471f8e86c1653386205e372c6)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * xpath)` | Gets an element's Coords as an OGRMultiPolygon.
`public std::vector< `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` > `[`getOGRpolygons`](#class_page_x_m_l_1ad4ee556c6caa2572f2f7ee7aad14d458)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > nodes,const char * xpath)` | Gets elements' Coords as OGRMultiPolygons.
`public `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` `[`getUnionOGRpolygon`](#class_page_x_m_l_1afed5a7a57f5c0fcaf59a7dbb75811267)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > nodes,const char * xpath)` | Gets the union of Coords elements as a OGRMultiPolygon.
`public double `[`getOGRpolygonArea`](#class_page_x_m_l_1a9fa4920d5460e81c1e502cfaa9a8460d)`(`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly)` | Gets the area of a OGRMultiPolygon.
`public `[`OGRMultiLineStringPtr_`](#_page_x_m_l_8h_1a71f1fd7c15891a3cdd6da77bedcf1779)` `[`getOGRpolyline`](#class_page_x_m_l_1aa5af48c42eafdd9ddc98c242b8526c37)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * xpath)` | Gets the element's Baseline as an OGRMultiLineString.
`public `[`OGRMultiLineStringPtr_`](#_page_x_m_l_8h_1a71f1fd7c15891a3cdd6da77bedcf1779)` `[`multiPolylineIntersection`](#class_page_x_m_l_1aa9b03129f21e3ea045394caaeca06a6a)`(`[`OGRMultiLineStringPtr_`](#_page_x_m_l_8h_1a71f1fd7c15891a3cdd6da77bedcf1779)` poly1,`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly2)` | Computes the intersection between a multipolylines and a multipolygon.
`public `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` `[`multiPolygonIntersection`](#class_page_x_m_l_1a3fd32eea9e21803bcdaaae3a10fb1f1c)`(`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly1,`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly2)` | Computes the intersection of two multipolygons.
`public double `[`computeIntersectFactor`](#class_page_x_m_l_1a45dd1f4f006af562a90637420cd21f9c)`(`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly1,`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly2)` | Computes the intersection factor of one multipolygon over another.
`public double `[`computeIntersectFactor`](#class_page_x_m_l_1ac77c256502c08925bfc57068630d2756)`(`[`OGRMultiLineStringPtr_`](#_page_x_m_l_8h_1a71f1fd7c15891a3cdd6da77bedcf1779)` poly1,`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly2)` | Computes the intersection factor of one polyline over polygon.
`public double `[`computeIoU`](#class_page_x_m_l_1a3f29690f6a8b21819f95d2b2cbe4a182)`(`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly1,`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly2)` | Computes the intersection over union (IoU) of two polygons.
`public std::vector< double > `[`computeIoUs`](#class_page_x_m_l_1ad20b3e51b65a70de20085881378a074f)`(`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly,std::vector< `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` > polys)` | Computes the intersection over unions (IoU) of polygons.
`public double `[`computeIntersectionPercentage`](#class_page_x_m_l_1afa8011384f2029c861b48a536ba39b9a)`(`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly1,`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly2)` | Computes the intersection percentage of one polygon with respect to another polygons.
`public std::vector< double > `[`computeIntersectionPercentages`](#class_page_x_m_l_1ac1e9141dddb77e569afc962a0bf8548c)`(`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly,std::vector< `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` > polys)` | Computes the intersection percentage of one polygon with respect to other polygons.
`public std::vector< double > `[`computeAreas`](#class_page_x_m_l_1af0986a35b548f3ce33516281221ff303)`(std::vector< `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` > polys)` | Computes the areas for given polygons.
`public std::vector< double > `[`computeCoordsIntersectionsWeightedByArea`](#class_page_x_m_l_1a0b66bebe169432bc92dc0d36bfaa539b)`(`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly,std::vector< `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` > polys,std::vector< double > areas)` | Computes polygon-polygon intersections weighted by area.
`public std::vector< double > `[`computeBaselineIntersectionsWeightedByArea`](#class_page_x_m_l_1a1fdc1df063018096d26a9dc34ce0faad)`(`[`OGRMultiLineStringPtr_`](#_page_x_m_l_8h_1a71f1fd7c15891a3cdd6da77bedcf1779)` poly,std::vector< `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` > polys,std::vector< double > areas)` | Computes line-polygon intersections weighted by area.
`public std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > `[`selectByOverlap`](#class_page_x_m_l_1a3718a39284bb9e947e19af32b75a00cb)`(std::vector< cv::Point2f > points,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` page,const char * xpath,double overlap_thr,`[`PAGEXML_OVERLAP`](#_page_x_m_l_8h_1a8606ef3ee6c75085c7c5d97b79132c50)` overlap_type)` | Selects elements based on overlap to a polygon.
`public std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > `[`selectByOverlap`](#class_page_x_m_l_1a5f355663308e4f139495d06015a4854f)`(std::vector< cv::Point2f > points,int pagenum,const char * xpath,double overlap_thr,`[`PAGEXML_OVERLAP`](#_page_x_m_l_8h_1a8606ef3ee6c75085c7c5d97b79132c50)` overlap_type)` | Selects elements based on overlap to a polygon.
`public int `[`copyTextLinesAssignByOverlap`](#class_page_x_m_l_1ae4b049403a387f9455bc0cc3026a7b76)`(`[`PageXML`](#class_page_x_m_l)` & pageFrom,`[`PAGEXML_OVERLAP`](#_page_x_m_l_8h_1a8606ef3ee6c75085c7c5d97b79132c50)` overlap_type,double overlap_fact)` | Copies TextLines from one page xml to another assigning to regions based on overlap.
`public int `[`getLeftRightTextContinuationGroups`](#class_page_x_m_l_1a956e914f402e0414a016d51e5fc5e05c)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > elems,std::vector< std::vector< int > > & _group_order,std::vector< double > & _group_score,double max_angle_diff,double max_horiz_iou,double min_prolong_fact,double prolong_alpha,bool fake_baseline,double recurse_factor)` | Determines groups of left-right text elem continuations (requires single segment polystripe).
`public std::pair< std::vector< int >, std::vector< int > > `[`getLeftRightTopBottomReadingOrder`](#class_page_x_m_l_1abcae8ac441e73b385d2bc0334bfb3d51)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > elems,double max_angle_diff,double max_horiz_iou,double min_prolong_fact,double prolong_alpha,bool fake_baseline,double recurse_factor)` | Gets the reading order for a set of text elems (requires single segment polystripe).
`public xmlDocPtr `[`getDocPtr`](#class_page_x_m_l_1a279bbf7b7641aa329f9fd5607cdde52c)`()` | Returns the XML document pointer.

## Members

#### `public  `[`~PageXML`](#class_page_x_m_l_1accc94a5c0375b71fd2f058abc04ca25e)`()` 

[PageXML](#class_page_x_m_l) object destructor.

#### `public  `[`PageXML`](#class_page_x_m_l_1a0b930b74d48fe26bdfbfee7cde0df960)`(const char * pagexml_path,const char * schema_path)` 

Constructors ///.

[PageXML](#class_page_x_m_l) constructor that receives a file name to load.

#### Parameters
* `pagexml_path` Path to the XML file to read. 

* `schema_path` Path to the XSD file to read.

#### `public void `[`loadSchema`](#class_page_x_m_l_1a26f73cb3afd642889c5c6e7e5bd4a2ba)`(const char * schema_path)` 

Loads a schema for xml validation.

#### Parameters
* `schema_path` File name of the XSD file to read.

#### `public bool `[`isValid`](#class_page_x_m_l_1a3ae4157e63f4252bae130e20f63181f7)`()` 

Validates the currently loaded XML.

#### `public void `[`printConf`](#class_page_x_m_l_1a2f243e564f59e0e86be34fb3641526e0)`(FILE * file)` 

Configuration ///.

Prints the current configuration.

#### Parameters
* `file` File to print to.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`newXml`](#class_page_x_m_l_1a95f40947e6da8415578a4dcaf7a8eea3)`(const char * creator,const char * image,const int imgW,const int imgH)` 

Loaders ///.

Creates a new Page XML.

#### Parameters
* `creator` Info about tool creating the XML. 

* `image` Path to the image file. 

* `imgW` Width of image. 

* `imgH` Height of image.

#### `public void `[`loadXml`](#class_page_x_m_l_1a4ec7578dd9794ac300d9bbf1e04d6f55)`(const char * fname,bool validate)` 

Loads a Page XML from a file.

#### Parameters
* `fname` File name of the XML file to read.

#### `public void `[`loadXml`](#class_page_x_m_l_1a803d631c80ea3cc9d93b03a791fb560c)`(int fnum,bool prevfree,bool validate)` 

Loads a Page XML from an input stream.

#### Parameters
* `fnum` File number from where to read the XML file. 

* `prevfree` Whether to release resources before loading.

#### `public void `[`loadXmlString`](#class_page_x_m_l_1a70b4da88ce7f75a92fc3127e7b7e5c1f)`(const char * xml_string,bool validate)` 

Loads a Page XML from a string.

#### Parameters
* `xml_string` The XML content.

#### `public void `[`releaseImage`](#class_page_x_m_l_1a42af7ec35f05910aa3fa322f053240be)`(int pagenum)` 

Releases an already loaded image.

#### Parameters
* `pagenum` The number of the page for which to release the image.

#### `public void `[`releaseImage`](#class_page_x_m_l_1a7ae389bfa05769d488568131fa4a49fd)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

#### `public void `[`releaseImages`](#class_page_x_m_l_1ae8f1b698bf3abeee79a84d79dc877b7d)`()` 

#### `public void `[`loadImage`](#class_page_x_m_l_1acc541aed93c06fdfeec29ad217f217a8)`(int pagenum,const char * fname,const bool resize_coords,int density)` 

#### `public void `[`loadImage`](#class_page_x_m_l_1a74593bb0b4ca5e266dfc5650ca5009d0)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * fname,const bool resize_coords,int density)` 

#### `public void `[`loadImages`](#class_page_x_m_l_1a21450ed106a7a385b9b391b6cb033d4c)`(const bool resize_coords,const int density)` 

#### `public int `[`simplifyIDs`](#class_page_x_m_l_1a5d3b4a59cecbf6fdf8c84f806a7648f0)`()` 

Simplifies IDs by removing imgbase prefixes and replaces invalid characters with _.

#### Returns
Number of IDs simplified.

#### `public void `[`relativizeImageFilename`](#class_page_x_m_l_1a3c43349d7cff78cea6d1ba7b01f023b3)`(const char * xml_path)` 

Modifies imageFilename to be a relative path w.r.t. given xml path. Currently just checks prefix directories and removes it.

#### `public std::vector< std::string > `[`getImageBases`](#class_page_x_m_l_1a3c43f4e51877f674f29af7a421fa973b)`()` 

Gets image bases for all pages in xml.

#### Returns
Vector of strings containing the image base names.

#### `public bool `[`areIDsUnique`](#class_page_x_m_l_1aeb8f1e60e4e2521c2bb50fe495327648)`()` 

Verifies that all IDs in page are unique.

#### `public std::string `[`getNodeName`](#class_page_x_m_l_1a8e8ded73daa9edf93b02d75bac16b9de)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` base_node)` 

Gets the name of the given node.

#### Parameters
* `node` XML node. 

#### Returns
String with the name.

#### `public std::vector< `[`NamedImage`](#struct_named_image)` > `[`crop`](#class_page_x_m_l_1a3264214ef4bc3ea7d5706b33440c57a0)`(const char * xpath,cv::Point2f * margin,bool opaque_coords,const char * transp_xpath,const char * base_xpath)` 

Crops images using its Coords polygon, regions outside the polygon are set to transparent.

#### Parameters
* `xpath` Selector for polygons to crop. 

* `margin` Margins, if >1.0 pixels, otherwise percentage of maximum of crop width and height. 

* `opaque_coords` Whether to include an alpha channel with the polygon interior in opaque. 

* `transp_xpath` Selector for semi-transparent elements. 

#### Returns
An std::vector containing [NamedImage](#struct_named_image) objects of the cropped images.

#### `public int `[`count`](#class_page_x_m_l_1a4e96a80a41b38f74a9328eab24ed11a0)`(const char * xpath,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Returns number of matched nodes for a given xpath.

#### Parameters
* `xpath` Selector expression. 

* `node` XML node for context, set to NULL for root node. 

#### Returns
Number of matched nodes.

#### `public int `[`count`](#class_page_x_m_l_1a5817463d6e13c9472d1995e964ce28a7)`(std::string xpath,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

#### `public std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > `[`select`](#class_page_x_m_l_1a33d04b764e3a0c853ef7de78ca78cd41)`(const char * xpath,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Selects nodes given an xpath.

#### Parameters
* `xpath` Selector expression. 

* `node` XML node for context, set to NULL for root node. 

#### Returns
Vector of matched nodes.

#### `public std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > `[`select`](#class_page_x_m_l_1ad1fd441a90b31c4900bb9896185a177f)`(std::string xpath,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

#### `public std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > `[`select`](#class_page_x_m_l_1a6207c5d079018e4daff6de195ddf0512)`(const char * xpath,const std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > nodes,bool unique)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`selectNth`](#class_page_x_m_l_1a693a2275353703a06ae90427d59e416e)`(const char * xpath,int num,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Selects the n-th node that matches an xpath.

#### Parameters
* `xpath` Selector expression. 

* `num` Element number (0-indexed), negative from last. 

* `node` XML node for context, set to NULL for root node. 

#### Returns
Matched node.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`selectNth`](#class_page_x_m_l_1ae29d8b0b92240bc0866064c88c1eb0ab)`(std::string xpath,int num,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`selectByID`](#class_page_x_m_l_1ace787087add3c5f3016ec837553d48b5)`(const char * id,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Selects an element with a given ID.

#### Parameters
* `id` ID of element to select. 

* `node` XML node for context, set to NULL for root node. 

#### Returns
Matched node.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`closest`](#class_page_x_m_l_1a089e2ca706141bf750b301fd34595fc1)`(const char * name,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Selects closest node of a given name.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`parent`](#class_page_x_m_l_1a8ac32174f32b120caf595ec3a82e57d1)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Returns the parent of a node.

#### Parameters
* `node` XML node. 

#### Returns
Parent node.

#### `public std::string `[`getValue`](#class_page_x_m_l_1a806731e1825cfbfa406ddf3e6978d747)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Retrieves a node value.

#### Parameters
* `node` Node element. 

#### Returns
String with the node value.

#### `public std::string `[`getValue`](#class_page_x_m_l_1ae27ba3fb4d85e0ba2cee85125a6eaa54)`(const char * xpath,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Retrieves a node value.

#### Parameters
* `xpath` Selector for the element to get the value. 

* `node` XML node for context, set to NULL for root node. 

#### Returns
String with the node value.

#### `public void `[`setValue`](#class_page_x_m_l_1a67163afa48565eafd017cb134a324e6b)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * value)` 

Sets a node value.

#### Parameters
* `node` Node element. 

#### Returns
String with the node value.

#### `public std::string `[`getAttr`](#class_page_x_m_l_1a23e16f7c70950b4fe990b8c22a2e1ce5)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * name)` 

Gets an attribute value from an xml node.

#### Parameters
* `node` XML node. 

* `name` Attribute name. 

* `value` String to set the value. 

#### Returns
True if attribute found, otherwise false.

#### `public std::string `[`getAttr`](#class_page_x_m_l_1abef00c0a3b59143989b8d29beaeb14bf)`(const char * xpath,const char * name)` 

Gets an attribute value for a given xpath.

#### Parameters
* `xpath` Selector for the element to get the attribute. 

* `name` Attribute name. 

* `value` String to set the value. 

#### Returns
True if attribute found, otherwise false.

#### `public std::string `[`getAttr`](#class_page_x_m_l_1a057bb3cecf33b3cd2e621d56095a4716)`(const std::string xpath,const std::string name)` 

#### `public int `[`setAttr`](#class_page_x_m_l_1ada5a3f0e91615340782afe1eea87c23d)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > nodes,const char * name,const char * value)` 

#### `public int `[`setAttr`](#class_page_x_m_l_1abaa5b2ad59b0769bb8cff58a53b04231)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * name,const char * value)` 

Adds or modifies (if already exists) an attribute for a given node.

#### Parameters
* `node` Node to set the attribute. 

* `name` Attribute name. 

* `value` Attribute value. 

#### Returns
Number of elements modified.

#### `public int `[`setAttr`](#class_page_x_m_l_1a8cc6e9bffff7951aa5db47af47642601)`(const char * xpath,const char * name,const char * value)` 

Adds or modifies (if already exists) an attribute for a given xpath.

#### Parameters
* `xpath` Selector for the element(s) to set the attribute. 

* `name` Attribute name. 

* `value` Attribute value. 

#### Returns
Number of elements modified.

#### `public int `[`setAttr`](#class_page_x_m_l_1a8d1d681d5b986527265ff07c757a2b3b)`(const std::string xpath,const std::string name,const std::string value)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`insertElem`](#class_page_x_m_l_1ab0e8796f7920a2fc3ff1a490b85b6b8b)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype)` 

Inserts an element relative to a given node.

#### Parameters
* `elem` Element to insert. 

* `node` Reference element for insertion. 

* `itype` Type of insertion. 

#### Returns
Pointer to inserted element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addElem`](#class_page_x_m_l_1a2dd9a0a6cfeb68a91c005740dd6ce315)`(const char * name,const char * id,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype,bool checkid)` 

Creates a new element and adds it relative to a given node.

#### Parameters
* `name` Name of element to create. 

* `id` ID attribute for element. 

* `node` Reference element for insertion. 

* `itype` Type of insertion. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addElem`](#class_page_x_m_l_1a4b218c9cddda9763bdd3f65d3074d5f7)`(const char * name,const char * id,const char * xpath,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype,bool checkid)` 

Creates a new element and adds it relative to a given xpath.

#### Parameters
* `name` Name of element to create. 

* `id` ID attribute for element. 

* `xpath` Selector for insertion. 

* `itype` Type of insertion. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addElem`](#class_page_x_m_l_1abbbf302357d6016ffde3a2b859fa1f93)`(const std::string name,const std::string id,const std::string xpath,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype,bool checkid)` 

#### `public void `[`rmElem`](#class_page_x_m_l_1ad3e1cc3040a7aef670d64fac0e2e82d8)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Removes the given element.

#### Parameters
* `node` Element.

#### `public int `[`rmElems`](#class_page_x_m_l_1a58b3870ad811accb8b91a433796fbf6f)`(const std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > & nodes)` 

#### `public int `[`rmElems`](#class_page_x_m_l_1a615f87470132c8b50200e86492ffdf4c)`(const char * xpath,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Remove the elements that match a given xpath.

#### Parameters
* `xpath` Selector for elements to remove. 

* `node` Base node for element selection. 

#### Returns
Number of elements removed.

#### `public int `[`rmElems`](#class_page_x_m_l_1a1a47165a43b3de66729400c9a318c180)`(const std::string xpath,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`copyElem`](#class_page_x_m_l_1a40dc146d23d3e146ce2332764b1e913a)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype)` 

Clone an element and add it relative to a given node.

#### Parameters
* `elem` Element to clone. 

* `node` Reference element for insertion. 

* `itype` Type of insertion. 

#### Returns
Pointer to cloned element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`moveElem`](#class_page_x_m_l_1af214054f7b648086704f7cc0bd3b51e1)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype)` 

Unlink an element and add it relative to a given node.

#### Parameters
* `elem` Element to move. 

* `node` Reference element for insertion. 

* `itype` Type of insertion. 

#### Returns
Pointer to moved element.

#### `public int `[`moveElems`](#class_page_x_m_l_1ac6320b747e78baa3d2f5753086e54189)`(const std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > & elems,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype)` 

Unlink elements and add them relative to a given node.

#### Parameters
* `elems` Elements to move. 

* `node` Reference element for insertion. 

* `itype` Type of insertion. 

#### Returns
Pointer to moved element.

#### `public void `[`setRotation`](#class_page_x_m_l_1afc92cad64293df78c84bc7d8c899cf6f)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem,const float rotation)` 

Sets the rotation angle to a TextRegion node.

#### Parameters
* `node` Node of the TextRegion element. 

* `rotation` Rotation angle to set.

#### `public void `[`setReadingDirection`](#class_page_x_m_l_1af1eef0ce8e1ff941b79430db6802e51a)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem,`[`PAGEXML_READ_DIRECTION`](#_page_x_m_l_8h_1a151afb8ef7c7e05585713fafd180a2ea)` direction)` 

Sets the reading direction to a TextRegion node.

#### Parameters
* `node` Node of the TextRegion element. 

* `direction` Direction to set.

#### `public double `[`getDominantBaselinesOrientation`](#class_page_x_m_l_1ace699f89ee2dedc3304b2a7acf2c5135)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > elems)` 

Gets the dominant orientation angle for a set of baselines.

#### Parameters
* `elems` Nodes of the TextLine elements. 

#### Returns
The dominant orientation angle in radians, NaN if unset.

#### `public double `[`getBaselineOrientation`](#class_page_x_m_l_1a01d20d4333c5011f80bf83fe246ac76b)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem)` 

Gets the baseline orientation angle (weighted average over polyline segments) of a given text line.

#### Parameters
* `elem` Node of the TextLine element. 

#### Returns
The orientation angle in radians, NaN if unset.

#### `public double `[`getPolylineOrientation`](#class_page_x_m_l_1a3b765fd1a88f7c36eac75b68e87dd010)`(std::vector< cv::Point2f > points)` 

Gets the baseline orientation angle (weighted average over polyline segments) in radians of a given baseline.

#### Parameters
* `points` Baseline points. 

#### Returns
The orientation angle in radians, NaN if unset.

#### `public double `[`getPolylineLength`](#class_page_x_m_l_1a234aa0cc97d29a247cc4b6f08d912206)`(std::vector< cv::Point2f > points)` 

Gets the baseline length.

#### Parameters
* `points` Baseline points. 

#### Returns
The orientation angle in radians, NaN if unset.

#### `public double `[`getRotation`](#class_page_x_m_l_1a6e68136a69dd82168bbc28c64bff45e4)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem)` 

Retrieves the rotation angle for a given TextLine or TextRegion node.

#### Parameters
* `elem` Node of the TextLine or TextRegion element. 

#### Returns
The rotation angle in degrees, 0 if unset.

#### `public int `[`getReadingDirection`](#class_page_x_m_l_1acc2adc9d4408836ea87d8056e2d522f6)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem)` 

Retrieves the reading direction for a given TextLine or TextRegion node.

#### Parameters
* `elem` Node of the TextLine or TextRegion element. 

#### Returns
The reading direction, PAGEXML_READ_DIRECTION_LTR if unset.

#### `public float `[`getXheight`](#class_page_x_m_l_1a6d7cd4ada93f19226e3723d6c41a9ebf)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Retrieves the x-height for a given TextLine node.

#### Parameters
* `node` Node of the TextLine element. 

#### Returns
x-height>0 on success, -1 if unset.

#### `public float `[`getXheight`](#class_page_x_m_l_1a401b8196ba181dec3fa5d76eb9c6e585)`(const char * id)` 

Retrieves the x-height for a given TextLine id.

#### Parameters
* `id` Identifier of the TextLine. 

#### Returns
x-height>0 on success, -1 if unset.

#### `public std::vector< cv::Point2f > `[`getFpgram`](#class_page_x_m_l_1a0425df4d97b66a7f259cfb1fae847667)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Retrieves the features parallelogram (Property[="fpgram"]/) for a given node.

#### Parameters
* `node` Base node. 

#### Returns
Reference to the points vector.

#### `public std::vector< cv::Point2f > `[`getPoints`](#class_page_x_m_l_1aba7be6cf9e66f1395c84f0880ca2a069)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * xpath)` 

Retrieves and parses the Coords/ for a given base node.

#### Parameters
* `node` Base node. 

#### Returns
Reference to the points vector.

#### `public std::vector< std::vector< cv::Point2f > > `[`getPoints`](#class_page_x_m_l_1a41e062ef2c08e4c3212c39d4ec48b2fa)`(const std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > nodes,const char * xpath)` 

Retrieves and parses the Coords/ for a given list of base nodes.

#### Parameters
* `nodes` Base nodes. 

#### Returns
Reference to the points vector.

#### `public std::string `[`getTextEquiv`](#class_page_x_m_l_1a00ab0efcf9edb0224208962c807e465f)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * xpath,const char * separator)` 

Retrieves the concatenated TextEquivs for a given root node and xpath.

#### Parameters
* `node` Root node element. 

* `xpath` Relative xpath to select the TextEquiv elements. 

* `separator` String to add between TextEquivs. 

#### Returns
String with the concatenated TextEquivs.

#### `public void `[`processStart`](#class_page_x_m_l_1a3eeffa37a2ace0dc732405e81cb49e4d)`(const char * tool,const char * ref)` 

Starts a process in the Page XML.

#### `public void `[`processEnd`](#class_page_x_m_l_1a29d780f46c1f14b241f48665d835394c)`()` 

Ends the running process in the Page XML.

#### `public void `[`updateLastChange`](#class_page_x_m_l_1a99bc8c45fae21207bb608e69609dedcd)`()` 

Updates the last change time stamp.

#### `public std::string `[`getPropertyValue`](#class_page_x_m_l_1ab4d79c28bc94086d1d379f0ea73ff899)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * key)` 

Retrieves a Property value.

#### Parameters
* `node` Node element. 

#### Returns
String with the property value.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setProperty`](#class_page_x_m_l_1af6e80d30313f63054228fcb15305db31)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * key,const char * val,const double * _conf)` 

Sets a Property to a given node.

#### Parameters
* `node` The node of element to set the Property. 

* `key` The key for the Property. 

* `val` The optional value for the Property. 

* `_conf` Pointer to confidence value, NULL for no confidence. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setProperty`](#class_page_x_m_l_1aa05ac4ccd18740e84e8566f5f07ed876)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * key,const char * val,const double conf)` 

Sets a Property to a given node.

#### Parameters
* `node` The node of element to set the Property. 

* `key` The key for the Property. 

* `val` The optional value for the Property. 

* `conf` Confidence value. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setProperty`](#class_page_x_m_l_1a82ffe7a5366736034a3e4514b43ab389)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * key,const double val,const double * _conf)` 

Sets a Property to a given node.

#### Parameters
* `node` The node of element to set the Property. 

* `key` The key for the Property. 

* `val` Numeric value for the Property. 

* `_conf` Pointer to confidence value, NULL for no confidence. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setProperty`](#class_page_x_m_l_1a8acc4a27f30da3f3d75c93baf5280a6d)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * key,const double val,const double conf)` 

Sets a Property to a given node.

#### Parameters
* `node` The node of element to set the Property. 

* `key` The key for the Property. 

* `val` The optional value for the Property. 

* `conf` Confidence value. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setTextEquiv`](#class_page_x_m_l_1a65f380acfc400de2a6dc59eb1ee22904)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * text,const double * _conf)` 

Adds or modifies (if already exists) the TextEquiv for a given node.

#### Parameters
* `node` The node of element to set the TextEquiv. 

* `text` The text string. 

* `_conf` Pointer to confidence value, NULL for no confidence. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setTextEquiv`](#class_page_x_m_l_1a3d01bccae1af691fc5cc60e720d1659b)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * text,const double conf)` 

Adds or modifies (if already exists) the TextEquiv for a given node.

#### Parameters
* `node` The node of element to set the TextEquiv. 

* `text` The text string. 

* `conf` Confidence value. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setTextEquiv`](#class_page_x_m_l_1ae7938084955a0668bc44f24307ad77ba)`(const char * xpath,const char * text,const double * _conf)` 

Adds or modifies (if already exists) the TextEquiv for a given xpath.

#### Parameters
* `xpath` Selector for element to set the TextEquiv. 

* `text` The text string. 

* `_conf` Pointer to confidence value, NULL for no confidence. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setTextEquiv`](#class_page_x_m_l_1aeaad48fa1ad577caa032534960e955f0)`(const char * xpath,const char * text,const double conf)` 

Adds or modifies (if already exists) the TextEquiv for a given xpath.

#### Parameters
* `xpath` Selector for element to set the TextEquiv. 

* `text` The text string. 

* `conf` Confidence value. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoords`](#class_page_x_m_l_1a8d92328ba656b8e8e847bf2ad3607a46)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const std::vector< cv::Point2f > & points,const double * _conf)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoords`](#class_page_x_m_l_1acf4d9ee3ef34fc928e4b3b0e53221284)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const std::vector< cv::Point2f > & points,const double conf)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoords`](#class_page_x_m_l_1a626847a8aac3c4bc650d0b27f3ce042b)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const std::vector< cv::Point > & points,const double * _conf)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoords`](#class_page_x_m_l_1a65dd07db2a1b0babba52c5d3423557e6)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const std::vector< cv::Point > & points,const double conf)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoords`](#class_page_x_m_l_1a1038c674a0522759ea3004bac9cac5f2)`(const char * xpath,const std::vector< cv::Point2f > & points,const double * _conf)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoords`](#class_page_x_m_l_1afbbded5bbdd2b5716782604aa5b22297)`(const char * xpath,const std::vector< cv::Point2f > & points,const double conf)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoordsBBox`](#class_page_x_m_l_1ac42051db4e4f1feb754401e78f5cb53d)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,double xmin,double ymin,double width,double height,const double * _conf,bool subone)` 

Adds or modifies (if already exists) the Coords as a bounding box for a given node.

#### Parameters
* `node` The node of element to set the Coords. 

* `xmin` Minimum x value of bounding box. 

* `ymin` Minimum y value of bounding box. 

* `width` Width of bounding box. 

* `height` Height of bounding box. 

* `_conf` Pointer to confidence value, NULL for no confidence. 

* `subone` Whether to subtract 1 when computing xmax and ymax (discrete compatibility). 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoordsBBox`](#class_page_x_m_l_1a2e4028e182c73058112b3d1009925c65)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,double xmin,double ymin,double width,double height,const double conf,bool subone)` 

Adds or modifies (if already exists) the Coords as a bounding box for a given node.

#### Parameters
* `node` The node of element to set the Coords. 

* `xmin` Minimum x value of bounding box. 

* `ymin` Minimum y value of bounding box. 

* `width` Width of bounding box. 

* `height` Height of bounding box. 

* `conf` Confidence value. 

* `subone` Whether to subtract 1 when computing xmax and ymax (discrete compatibility). 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setBaseline`](#class_page_x_m_l_1a2a85dc0b7eb35ac29780551a642a3e51)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const std::vector< cv::Point2f > & points,const double * _conf)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setBaseline`](#class_page_x_m_l_1a0d9eaff78f737a19fafe17b09c6b87fd)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const std::vector< cv::Point2f > & points,const double conf)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setBaseline`](#class_page_x_m_l_1a12a577c21cf6109f30843336bbdaba8d)`(const char * xpath,const std::vector< cv::Point2f > & points,const double * _conf)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setBaseline`](#class_page_x_m_l_1a9b2b8f89080a44663008d011c118801c)`(const char * xpath,const std::vector< cv::Point2f > & points,const double conf)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setBaseline`](#class_page_x_m_l_1a489cf14031d07454f538a048e4b48c03)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,double x1,double y1,double x2,double y2,const double * _conf)` 

Adds or modifies (if already exists) a two point Baseline for a given node.

#### Parameters
* `node` The node of element to set the Baseline. 

* `x1` x value of first point. 

* `y1` y value of first point. 

* `x2` x value of second point. 

* `y2` y value of second point. 

* `_conf` Pointer to confidence value, NULL for no confidence. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setBaseline`](#class_page_x_m_l_1af8a1bedc13b1c70a7bb6f249b8e34f52)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,double x1,double y1,double x2,double y2,const double conf)` 

Adds or modifies (if already exists) a two point Baseline for a given node.

#### Parameters
* `node` The node of element to set the Baseline. 

* `x1` x value of first point. 

* `y1` y value of first point. 

* `x2` x value of second point. 

* `y2` y value of second point. 

* `conf` Confidence value. 

#### Returns
Pointer to created element.

#### `public bool `[`intersection`](#class_page_x_m_l_1a37da0ed1fb708b374e7d83e6b22cbb23)`(cv::Point2f line1_point1,cv::Point2f line1_point2,cv::Point2f line2_point1,cv::Point2f line2_point2,cv::Point2f & _ipoint)` 

Finds the intersection point between two lines defined by pairs of points or returns false if no intersection

#### `public bool `[`isPolystripe`](#class_page_x_m_l_1a61c1b6597c7bcf7b65dc195e95ef7ab4)`(std::vector< cv::Point2f > coords,std::vector< cv::Point2f > baseline,double * height,double * offset)` 

Checks whether Coords is a poly-stripe for its corresponding baseline.

#### Parameters
* `coords` Coords points. 

* `baseline` Baseline points. 

* `offset` The offset of the poly-stripe (>=0 && <= 0.5). 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setPolystripe`](#class_page_x_m_l_1ab97470a0132a3e497c80f26e061aba28)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,double height,double offset,bool offset_check)` 

Sets the Coords of a TextLine as a poly-stripe of the baseline.

#### Parameters
* `node` The node of element to set the Coords. 

* `height` The height of the poly-stripe in pixels (>0). 

* `offset` The offset of the poly-stripe (>=0 && <= 0.5). 

#### Returns
Pointer to created element.

#### `public int `[`getPageNumber`](#class_page_x_m_l_1ae660a692143a9983406bba434037e78c)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Gets the page number for the given node.

#### `public void `[`setPageImageOrientation`](#class_page_x_m_l_1a7f89e6da35429f37f6d887b36510772c)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,int angle,const double * _conf)` 

Sets the image orientation for the given Page node.

#### Parameters
* `node` The page node. 

* `angle` The orientation angle in degrees {0,90,180,-90}. 

* `_conf` Pointer to confidence value, NULL for no confidence.

#### `public void `[`setPageImageOrientation`](#class_page_x_m_l_1ae2e91ca140cb87bd3fe4420fcab890fe)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,int angle,const double conf)` 

Sets the image orientation for the given Page node.

#### Parameters
* `node` The page node. 

* `angle` The orientation angle in degrees {0,90,180,-90}. 

* `conf` Confidence value.

#### `public void `[`setPageImageOrientation`](#class_page_x_m_l_1a94c03640c38f7ddd743b9c0423c71342)`(int pagenum,int angle,const double * _conf)` 

Sets the image orientation for the given Page number.

#### Parameters
* `pagenum` The page number (0-based). 

* `angle` The orientation angle in degrees {0,90,180,-90}. 

* `_conf` Pointer to confidence value, NULL for no confidence.

#### `public void `[`setPageImageOrientation`](#class_page_x_m_l_1ab08bc018507912fef86910f9f4822551)`(int pagenum,int angle,const double conf)` 

Sets the image orientation for the given Page number.

#### Parameters
* `pagenum` The page number (0-based). 

* `angle` The orientation angle in degrees {0,90,180,-90}. 

* `conf` Confidence value.

#### `public int `[`getPageImageOrientation`](#class_page_x_m_l_1a3f776930d7d1be6239497c49f6ea6b9a)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Gets the image orientation for the given node.

#### Parameters
* `node` A node to get its image orientation. 

#### Returns
Orientation in degrees.

#### `public int `[`getPageImageOrientation`](#class_page_x_m_l_1acd1a1b7bbe14a6c8e14e3ef5afccd3cf)`(int pagenum)` 

Gets the image orientation for the given Page number.

#### Parameters
* `pagenum` The page number (0-based). 

#### Returns
Orientation in degrees.

#### `public unsigned int `[`getPageWidth`](#class_page_x_m_l_1a7746613d3800267f27d7bef2240ec827)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Gets the width of a page (might be different to image width due to the image orientation).

#### Parameters
* `node` A node to get its page width. 

#### Returns
The page width.

#### `public unsigned int `[`getPageWidth`](#class_page_x_m_l_1aa1b7155d7ae5b37710310b7891d1c314)`(int pagenum)` 

Gets the width of a page (might be different to image width due to the image orientation).

#### Parameters
* `pagenum` The page number (0-based). 

#### Returns
The page width.

#### `public unsigned int `[`getPageHeight`](#class_page_x_m_l_1ab96562c1fe4d95706778507ed2e8b57d)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Gets the height of a page (might be different to image width due to the image orientation).

#### Parameters
* `node` A node to get its page height. 

#### Returns
The page height.

#### `public unsigned int `[`getPageHeight`](#class_page_x_m_l_1a80e90205b325157f3d1fd680f7ebc108)`(int pagenum)` 

Gets the height of a page (might be different to image width due to the image orientation).

#### Parameters
* `pagenum` The page number (0-based). 

#### Returns
The page height.

#### `public void `[`setPageWidth`](#class_page_x_m_l_1a4887c81a8f839015ff4643ba09193355)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,int width)` 

Sets the width of a page (actually sets imageWidth accounting for image orientation).

#### Parameters
* `node` A node to set its page width. 

* `width` The width to set.

#### `public void `[`setPageHeight`](#class_page_x_m_l_1acdd80beebd7ba3a38459ad46e103761e)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,int height)` 

Sets the height of a page (actually sets imageHeight accounting for image orientation).

#### Parameters
* `node` A node to set its page height. 

* `height` The height to set.

#### `public std::vector< cv::Size2i > `[`getPagesSize`](#class_page_x_m_l_1a525354fa982782061b40718607b960dd)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > pages)` 

Retrieves pages size.

#### Parameters
* `pages` Page nodes. 

#### Returns
Vector of page sizes.

#### `public std::vector< cv::Size2i > `[`getPagesSize`](#class_page_x_m_l_1aab0456c928c85b694387acf75339c02f)`(const char * xpath)` 

Retrieves pages size.

#### Parameters
* `xpath` Selector for Page nodes. 

#### Returns
Vector of page sizes.

#### `public int `[`rotatePage`](#class_page_x_m_l_1a66d218878c54780c72ec9edda4b1d72e)`(int angle,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` page,bool update_image_orientation,const double conf)` 

Rotates a page.

#### Parameters
* `angle` Angle to rotate in degrees {0,90,180,-90}. 

* `page` The Page node. 

* `update_image_orientation` Whether to update the ImageOrientation element. 

* `conf` Confidence value. 

#### Returns
Number of elements modified.

#### `public int `[`rotatePage`](#class_page_x_m_l_1afd756366f58bb47b0f1961fce3dcbe71)`(int angle,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` page,bool update_image_orientation,const double * _conf)` 

Rotates a page.

#### Parameters
* `angle` Angle to rotate in degrees {0,90,180,-90}. 

* `page` The Page node. 

* `update_image_orientation` Whether to check that the aspect ratio is properly preserved. 

* `_conf` Pointer to confidence value, NULL for no confidence. 

#### Returns
Number of elements modified.

#### `public int `[`resize`](#class_page_x_m_l_1a81f6aa2af3574985f268959662ac4c2b)`(std::vector< cv::Size2i > sizes,std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > pages,bool check_aspect_ratio)` 

Resizes pages and all respective coordinates.

#### Parameters
* `sizes` Page sizes to resize to. 

* `pages` Page nodes. 

* `check_aspect_ratio` Whether to check that the aspect ratio is properly preserved. 

#### Returns
Number of pages+points attributes modified.

#### `public int `[`resize`](#class_page_x_m_l_1a8b24748e08ccb010eb709a9d91c711cc)`(std::vector< cv::Size2i > sizes,const char * xpath,bool check_aspect_ratio)` 

Resizes pages and all respective coordinates.

#### Parameters
* `sizes` Page sizes to resize to. 

* `xpath` Selector for Page nodes. 

* `check_aspect_ratio` Whether to check that the aspect ratio is properly preserved. 

#### Returns
Number of pages+points attributes modified.

#### `public int `[`resize`](#class_page_x_m_l_1ae9772185b88e2e12e26025effc2c39c7)`(cv::Size2i size,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` page,bool check_aspect_ratio)` 

Resizes a page and all respective coordinates.

#### Parameters
* `size` Page size to resize to. 

* `page` Page node. 

* `check_aspect_ratio` Whether to check that the aspect ratio is properly preserved. 

#### Returns
Number of pages+points attributes modified.

#### `public int `[`resize`](#class_page_x_m_l_1a06f171653bd8d50c03ed153523e24fc5)`(double fact,const char * xpath)` 

Resizes a page and all respective coordinates.

#### Parameters
* `factor` Resizing factor. 

* `xpath` Selector for Page nodes. 

#### Returns
Number of pages+points attributes modified.

#### `public void `[`setPageImageFilename`](#class_page_x_m_l_1a66d14b834c2ff1e162ddc268d92e9318)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * image)` 

Sets the imageFilename of a page.

#### `public void `[`setPageImageFilename`](#class_page_x_m_l_1a1f6225549414316c7b42d466f37ea9ae)`(int pagenum,const char * image)` 

#### `public std::string `[`getPageImageFilename`](#class_page_x_m_l_1ab6670ff942eeb850d64cb87a9932be58)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Returns the imageFilename of a page.

#### `public std::string `[`getPageImageFilename`](#class_page_x_m_l_1ac6fe17760af6634bf781b82831f6145b)`(int pagenum)` 

#### `public bool `[`isPageImageLoaded`](#class_page_x_m_l_1a5c2c180d3f973cccf9c2a19ce2966d54)`(int pagenum)` 

Checks whether a page image is loaded.

#### `public bool `[`isPageImageLoaded`](#class_page_x_m_l_1aba6d1e7beb4eb3fb419c4f8dc625e8a3)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

#### `public `[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` `[`getPageImage`](#class_page_x_m_l_1acc09b01d19dfafb3ccd43b0099313045)`(int pagenum)` 

Returns the image for the given page.

#### `public `[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` `[`getPageImage`](#class_page_x_m_l_1abf54fa39f33ca21661e87528136b00b6)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addGlyph`](#class_page_x_m_l_1a0814aa1518e897289014c38c441a8bf1)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * id,const char * before_id)` 

Adds a Glyph to a given node.

#### Parameters
* `node` The node of element to add the Glyph. 

* `id` ID for Glyph, if NULL it is selected automatically. 

* `before_id` If !=NULL inserts it before the Glyph with this ID. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addGlyph`](#class_page_x_m_l_1acaa1832064f9fadb99580bce37ff2a61)`(const char * xpath,const char * id,const char * before_id)` 

Adds a Glyph to a given xpath.

#### Parameters
* `xpath` Selector for element to set the Glyph. 

* `id` ID for Glyph, if NULL it is selected automatically. 

* `before_id` If !=NULL inserts it before the Glyph with this ID. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addWord`](#class_page_x_m_l_1ab865d14cd40a7898f7612ca3e1cb507f)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * id,const char * before_id)` 

Adds a Word to a given node.

#### Parameters
* `node` The node of element to add the Word. 

* `id` ID for Word, if NULL it is selected automatically. 

* `before_id` If !=NULL inserts it before the Word with this ID. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addWord`](#class_page_x_m_l_1a35b83528a5e85c0f8e5fe91e6603ea7f)`(const char * xpath,const char * id,const char * before_id)` 

Adds a Word to a given xpath.

#### Parameters
* `xpath` Selector for element to set the Word. 

* `id` ID for Word, if NULL it is selected automatically. 

* `before_id` If !=NULL inserts it before the Word with this ID. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addTextLine`](#class_page_x_m_l_1a990faea859827afc6ed10243f1c347fb)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * id,const char * before_id)` 

Adds a TextLine to a given node.

#### Parameters
* `node` The node of element to add the TextLine. 

* `id` ID for TextLine, if NULL it is selected automatically. 

* `before_id` If !=NULL inserts it before the TextLine with this ID. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addTextLine`](#class_page_x_m_l_1a52798d2245ba8af0afb948b31b311243)`(const char * xpath,const char * id,const char * before_id)` 

Adds a TextLine to a given xpath.

#### Parameters
* `xpath` Selector for element to add the TextLine. 

* `id` ID for TextLine, if NULL it is selected automatically. 

* `before_id` If !=NULL inserts it before the TextLine with this ID. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addTextRegion`](#class_page_x_m_l_1af335dbda4b11ddc8078df72ffca38f7c)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * id,const char * before_id,bool prepend)` 

Adds a TextRegion to a given node.

#### Parameters
* `node` The node of element to add the TextRegion. 

* `id` ID for TextRegion, if NULL it is selected automatically. 

* `before_id` If !=NULL inserts it before the TextRegion with this ID. 

* `prepend` Whether to add element before all other TextRegions. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addTextRegion`](#class_page_x_m_l_1afd831d3d6a2a33cc53feae4e4c3b4662)`(const char * xpath,const char * id,const char * before_id,bool prepend)` 

Adds new TextRegion to a given xpath.

#### Parameters
* `xpath` Selector for element to add the TextRegion. 

* `id` ID for TextRegion, if NULL it is selected automatically. 

* `before_id` If !=NULL inserts it before the TextRegion with this ID. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addPage`](#class_page_x_m_l_1a99fbe6075faea2c881f8a5bbb2d68f0e)`(const char * image,const int imgW,const int imgH,const char * id,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` before_node)` 

Adds a Page to the PcGts node.

#### Parameters
* `image` Path to the image file. 

* `imgW` Width of image. 

* `imgH` Height of image. 

* `id` ID for Page, if NULL it is left unset. 

* `before_node` If !=NULL inserts it before the provided Page node. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addPage`](#class_page_x_m_l_1ad7c0aed4a410245017724a7cefc40654)`(std::string image,const int imgW,const int imgH,const char * id,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` before_node)` 

Adds a Page to the PcGts node.

#### Parameters
* `image` Path to the image file. 

* `imgW` Width of image. 

* `imgH` Height of image. 

* `id` ID for Page, if NULL it is left unset. 

* `before_node` If !=NULL inserts it before the provided Page node. 

#### Returns
Pointer to created element.

#### `public int `[`write`](#class_page_x_m_l_1a0c4b94eb5f607e85d8ae27a93e571f5f)`(const char * fname,bool validate)` 

Output ///.

Writes the current state of the XML to a file using utf-8 encoding.

#### Parameters
* `fname` File name of where the XML file will be written. 

#### Returns
Number of bytes written.

#### `public std::string `[`toString`](#class_page_x_m_l_1af19593957ab5019cfa2e606d31b000e2)`(bool validate)` 

Creates a string representation of the Page XML.

#### `public `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` `[`pointsToOGRpolygon`](#class_page_x_m_l_1a4748cef2a547bb364d5a5e0bc15ccbc7)`(std::vector< cv::Point2f > points)` 

Converts Coords to an OGRMultiPolygon.

#### Parameters
* `points` Vector of x,y points. 

#### Returns
Pointer to OGRMultiPolygon element.

#### `public std::vector< `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` > `[`pointsToOGRpolygons`](#class_page_x_m_l_1a1655a09ca1b847b129db72d6b5b56d0b)`(std::vector< std::vector< cv::Point2f > > points)` 

Converts Coords to OGRMultiPolygons.

#### Parameters
* `points` Vectors of x,y points. 

#### Returns
Pointer to OGRMultiPolygon element.

#### `public `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` `[`getOGRpolygon`](#class_page_x_m_l_1a3e9e0aa471f8e86c1653386205e372c6)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * xpath)` 

Gets an element's Coords as an OGRMultiPolygon.

#### Parameters
* `node` The element from which to extract the Coords points. 

* `xpath` Selector for the Coords element. 

#### Returns
Pointer to OGRMultiPolygon element.

#### `public std::vector< `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` > `[`getOGRpolygons`](#class_page_x_m_l_1ad4ee556c6caa2572f2f7ee7aad14d458)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > nodes,const char * xpath)` 

Gets elements' Coords as OGRMultiPolygons.

#### Parameters
* `nodes` Elements from which to extract the Coords points. 

* `xpath` Selector for the Coords element. 

#### Returns
Vector of OGRMultiPolygon pointer elements.

#### `public `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` `[`getUnionOGRpolygon`](#class_page_x_m_l_1afed5a7a57f5c0fcaf59a7dbb75811267)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > nodes,const char * xpath)` 

Gets the union of Coords elements as a OGRMultiPolygon.

#### Parameters
* `nodes` Elements from which to extract the Coords points. 

* `xpath` Selector for the Coords element. 

#### Returns
Pointer to OGRMultiPolygon element.

#### `public double `[`getOGRpolygonArea`](#class_page_x_m_l_1a9fa4920d5460e81c1e502cfaa9a8460d)`(`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly)` 

Gets the area of a OGRMultiPolygon.

#### Parameters
* `poly` OGRMultiPolygon pointer. 

#### Returns
Area.

#### `public `[`OGRMultiLineStringPtr_`](#_page_x_m_l_8h_1a71f1fd7c15891a3cdd6da77bedcf1779)` `[`getOGRpolyline`](#class_page_x_m_l_1aa5af48c42eafdd9ddc98c242b8526c37)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * xpath)` 

Gets the element's Baseline as an OGRMultiLineString.

#### Parameters
* `node` The element from which to extract the Baseline points. 

#### Returns
Pointer to OGRMultiLineString element.

#### `public `[`OGRMultiLineStringPtr_`](#_page_x_m_l_8h_1a71f1fd7c15891a3cdd6da77bedcf1779)` `[`multiPolylineIntersection`](#class_page_x_m_l_1aa9b03129f21e3ea045394caaeca06a6a)`(`[`OGRMultiLineStringPtr_`](#_page_x_m_l_8h_1a71f1fd7c15891a3cdd6da77bedcf1779)` poly1,`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly2)` 

Computes the intersection between a multipolylines and a multipolygon.

#### Parameters
* `poly1` Polyline. 

* `poly2` Polygon. 

#### Returns
Intersection geometry.

#### `public `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` `[`multiPolygonIntersection`](#class_page_x_m_l_1a3fd32eea9e21803bcdaaae3a10fb1f1c)`(`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly1,`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly2)` 

Computes the intersection of two multipolygons.

#### Parameters
* `poly1` First polygon. 

* `poly2` Second polygon. 

#### Returns
Intersection geometry.

#### `public double `[`computeIntersectFactor`](#class_page_x_m_l_1a45dd1f4f006af562a90637420cd21f9c)`(`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly1,`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly2)` 

Computes the intersection factor of one multipolygon over another.

#### Parameters
* `poly1` First polygon. 

* `poly2` Second polygon. 

#### Returns
Factor value.

#### `public double `[`computeIntersectFactor`](#class_page_x_m_l_1ac77c256502c08925bfc57068630d2756)`(`[`OGRMultiLineStringPtr_`](#_page_x_m_l_8h_1a71f1fd7c15891a3cdd6da77bedcf1779)` poly1,`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly2)` 

Computes the intersection factor of one polyline over polygon.

#### Parameters
* `poly1` Polyline. 

* `poly2` Polygon. 

#### Returns
Factor value.

#### `public double `[`computeIoU`](#class_page_x_m_l_1a3f29690f6a8b21819f95d2b2cbe4a182)`(`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly1,`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly2)` 

Computes the intersection over union (IoU) of two polygons.

#### Parameters
* `poly1` First polygon. 

* `poly2` Second polygon. 

#### Returns
IoU value.

#### `public std::vector< double > `[`computeIoUs`](#class_page_x_m_l_1ad20b3e51b65a70de20085881378a074f)`(`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly,std::vector< `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` > polys)` 

Computes the intersection over unions (IoU) of polygons.

#### Parameters
* `poly` Polygon. 

* `polys` Vector of polygons. 

#### Returns
IoU values.

#### `public double `[`computeIntersectionPercentage`](#class_page_x_m_l_1afa8011384f2029c861b48a536ba39b9a)`(`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly1,`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly2)` 

Computes the intersection percentage of one polygon with respect to another polygons.

#### Parameters
* `poly1` First polygon. 

* `poly2` Second polygon. 

#### Returns
Intersection percentage value.

#### `public std::vector< double > `[`computeIntersectionPercentages`](#class_page_x_m_l_1ac1e9141dddb77e569afc962a0bf8548c)`(`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly,std::vector< `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` > polys)` 

Computes the intersection percentage of one polygon with respect to other polygons.

#### Parameters
* `poly` Polygon. 

* `polys` Vector of polygons. 

#### Returns
Intersection percentage values.

#### `public std::vector< double > `[`computeAreas`](#class_page_x_m_l_1af0986a35b548f3ce33516281221ff303)`(std::vector< `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` > polys)` 

Computes the areas for given polygons.

#### Parameters
* `polys` Polygons to process. 

#### Returns
The polygon areas.

#### `public std::vector< double > `[`computeCoordsIntersectionsWeightedByArea`](#class_page_x_m_l_1a0b66bebe169432bc92dc0d36bfaa539b)`(`[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` poly,std::vector< `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` > polys,std::vector< double > areas)` 

Computes polygon-polygon intersections weighted by area.

#### Parameters
* `poly` Polygon. 

* `polys` Polygons to compare with. 

* `areas` Polygons areas. 

#### Returns
Obtained intersection scores.

#### `public std::vector< double > `[`computeBaselineIntersectionsWeightedByArea`](#class_page_x_m_l_1a1fdc1df063018096d26a9dc34ce0faad)`(`[`OGRMultiLineStringPtr_`](#_page_x_m_l_8h_1a71f1fd7c15891a3cdd6da77bedcf1779)` poly,std::vector< `[`OGRMultiPolygonPtr_`](#_page_x_m_l_8h_1a217bb76bfe8145c889b9a5ae8927a11c)` > polys,std::vector< double > areas)` 

Computes line-polygon intersections weighted by area.

#### Parameters
* `poly` Polyline. 

* `polys` Polygons to compare with. 

* `areas` Polygons areas. 

#### Returns
Obtained intersection scores.

#### `public std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > `[`selectByOverlap`](#class_page_x_m_l_1a3718a39284bb9e947e19af32b75a00cb)`(std::vector< cv::Point2f > points,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` page,const char * xpath,double overlap_thr,`[`PAGEXML_OVERLAP`](#_page_x_m_l_8h_1a8606ef3ee6c75085c7c5d97b79132c50)` overlap_type)` 

Selects elements based on overlap to a polygon.

#### Parameters
* `points` Polygon for selection. 

* `page` Page element for selection. 

* `xpath` xpath for candidate elements for selection. 

* `overlap_thr` Overlapping score threshold. 

* `overlap_type` Type of overlap to use for selecting. 

#### Returns
Number of TextLines copied.

#### `public std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > `[`selectByOverlap`](#class_page_x_m_l_1a5f355663308e4f139495d06015a4854f)`(std::vector< cv::Point2f > points,int pagenum,const char * xpath,double overlap_thr,`[`PAGEXML_OVERLAP`](#_page_x_m_l_8h_1a8606ef3ee6c75085c7c5d97b79132c50)` overlap_type)` 

Selects elements based on overlap to a polygon.

#### Parameters
* `points` Polygon for selection. 

* `pagenum` Page number for selection. 

* `xpath` xpath for candidate elements for selection. 

* `overlap_thr` Overlapping score threshold. 

* `overlap_type` Type of overlap to use for selecting. 

#### Returns
Number of TextLines copied.

#### `public int `[`copyTextLinesAssignByOverlap`](#class_page_x_m_l_1ae4b049403a387f9455bc0cc3026a7b76)`(`[`PageXML`](#class_page_x_m_l)` & pageFrom,`[`PAGEXML_OVERLAP`](#_page_x_m_l_8h_1a8606ef3ee6c75085c7c5d97b79132c50)` overlap_type,double overlap_fact)` 

Copies TextLines from one page xml to another assigning to regions based on overlap.

#### Parameters
* `pageFrom` [PageXML](#class_page_x_m_l) from where to copy TextLines. 

* `overlap_type` Type of overlap to use for assigning lines to regions. 

* `overlap_fact` Overlapping factor. 

#### Returns
Number of TextLines copied.

#### `public int `[`getLeftRightTextContinuationGroups`](#class_page_x_m_l_1a956e914f402e0414a016d51e5fc5e05c)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > elems,std::vector< std::vector< int > > & _group_order,std::vector< double > & _group_score,double max_angle_diff,double max_horiz_iou,double min_prolong_fact,double prolong_alpha,bool fake_baseline,double recurse_factor)` 

Determines groups of left-right text elem continuations (requires single segment polystripe).

#### Parameters
* `elems` Text elements to test for continuation: TextLines, Words, Glyphs or TextRegions. 

* `_group_order` Join groups line indices (output). 

* `_group_score` Join group scores (output). 

* `max_angle_diff` Maximum baseline angle difference for joining. 

* `max_horiz_iou` Maximum horizontal IoU for joining. 

* `min_prolong_fact` Minimum prolongation factor for joining. 

* `prolong_alpha` Weight for prolongation factors: alpha*bline+(1-alpha)*coords. 

* `fake_baseline` Use bottom line of Coords rectangle as the baseline. 

* `recurse_factor` Multiplication factor for continuation criteria on each recursion. 

#### Returns
Number of join groups, elements per group in order and group scores.

#### `public std::pair< std::vector< int >, std::vector< int > > `[`getLeftRightTopBottomReadingOrder`](#class_page_x_m_l_1abcae8ac441e73b385d2bc0334bfb3d51)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > elems,double max_angle_diff,double max_horiz_iou,double min_prolong_fact,double prolong_alpha,bool fake_baseline,double recurse_factor)` 

Gets the reading order for a set of text elems (requires single segment polystripe).

#### Parameters
* `elems` Elements to process: TextLines, Words, Glyphs or TextRegions. 

* `max_angle_diff` Maximum baseline angle difference for joining. 

* `max_horiz_iou` Maximum horizontal IoU for joining. 

* `min_prolong_fact` Minimum prolongation factor for joining. 

* `prolong_alpha` Weight for prolongation factors: alpha*bline+(1-alpha)*coords. 

* `fake_baseline` Use bottom line of Coords rectangle as the baseline. 

* `recurse_factor` Multiplication factor for continuation criteria on each recursion. 

#### Returns
Pair of reading order indices and subgroup lengths.

#### `public xmlDocPtr `[`getDocPtr`](#class_page_x_m_l_1a279bbf7b7641aa329f9fd5607cdde52c)`()` 

Returns the XML document pointer.

# class `TextFeatExtractor` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`TextFeatExtractor`](#class_text_feat_extractor_1abe07fda5dc6d2ad0fb6b371fdfc8b4ba)`(int featype,int format,bool verbose,bool procimgs,bool stretch,bool enh,int enh_type,int enh_win,float enh_slp,float enh_prm,float enh_prm_randmin,float enh_prm_randmax,float enh3_prm0,float enh3_prm2,bool deslope,bool deslant,float deslant_min,float deslant_max,float deslant_step,int deslant_hsteps,float slant_rand,float scale_rand,int normxheight,int normheight,bool momentnorm,bool compute_fpgram,bool compute_fcontour,float fcontour_dilate,int padding)` | Constructors ///.
`public void `[`printConf`](#class_text_feat_extractor_1a44524c318c2a2eb3e4b38ef0eed4bff5)`(FILE * file)` | Configuration ///.
`public void `[`preprocess`](#class_text_feat_extractor_1ae861ca4ba44a9d9000f9d90c96b500c8)`(`[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` & cvimg,std::vector< cv::Point > * _fcontour,bool randomize)` | Pre-processes a text image, optionally computing the connected components contour.
`public void `[`estimateAngles`](#class_text_feat_extractor_1aaa88ad10c4a1aba39acb951c46cce460)`(`[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` & cvimg,float * _slope,float * _slant,float rotate)` | Estimates slope and slant angles for an image.
`public cv::Mat `[`extractFeats`](#class_text_feat_extractor_1a5b060ca5dea2c64820702f86d448cd5d)`(`[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` & feaimg,float slope,float slant,int xheight,std::vector< cv::Point2f > * _fpgram,bool randomize,float rotate,int direction)` | Extracts features for the given image already preprocessed image.
`public bool `[`isImageFormat`](#class_text_feat_extractor_1abb7da8622bf364ef6bf5513779497d04)`()` | Whether the configured output format is image.
`public void `[`write`](#class_text_feat_extractor_1aed77454431dd4d5e5c6d666e5cc10bfa)`(const cv::Mat & feats,FILE * file)` | Prints features to a file stream using the configured output format.
`public void `[`write`](#class_text_feat_extractor_1ad59b31da84822d8f3ca24e80e778b7da)`(const cv::Mat & feats,const char * fname)` | Writes features to a file using the configured output format.

## Members

#### `public  `[`TextFeatExtractor`](#class_text_feat_extractor_1abe07fda5dc6d2ad0fb6b371fdfc8b4ba)`(int featype,int format,bool verbose,bool procimgs,bool stretch,bool enh,int enh_type,int enh_win,float enh_slp,float enh_prm,float enh_prm_randmin,float enh_prm_randmax,float enh3_prm0,float enh3_prm2,bool deslope,bool deslant,float deslant_min,float deslant_max,float deslant_step,int deslant_hsteps,float slant_rand,float scale_rand,int normxheight,int normheight,bool momentnorm,bool compute_fpgram,bool compute_fcontour,float fcontour_dilate,int padding)` 

Constructors ///.

#### `public void `[`printConf`](#class_text_feat_extractor_1a44524c318c2a2eb3e4b38ef0eed4bff5)`(FILE * file)` 

Configuration ///.

Prints the current configuration.

#### Parameters
* `file` File to print to.

#### `public void `[`preprocess`](#class_text_feat_extractor_1ae861ca4ba44a9d9000f9d90c96b500c8)`(`[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` & cvimg,std::vector< cv::Point > * _fcontour,bool randomize)` 

Pre-processes a text image, optionally computing the connected components contour.

#### Parameters
* `image` Image to process. 

* `_fcontour` Output contour points, set to NULL to skip computation. 

* `randomize` Whether to do a random perturbation of preprocessing parameters.

#### `public void `[`estimateAngles`](#class_text_feat_extractor_1aaa88ad10c4a1aba39acb951c46cce460)`(`[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` & cvimg,float * _slope,float * _slant,float rotate)` 

Estimates slope and slant angles for an image.

#### Parameters
* `image` Image to process. 

* `_slope` Estimated slope angle in degrees. 

* `_slant` Estimated slant angle in degrees.

#### `public cv::Mat `[`extractFeats`](#class_text_feat_extractor_1a5b060ca5dea2c64820702f86d448cd5d)`(`[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` & feaimg,float slope,float slant,int xheight,std::vector< cv::Point2f > * _fpgram,bool randomize,float rotate,int direction)` 

Extracts features for the given image already preprocessed image.

#### Parameters
* `feaimg` Image to process. 

* `slope` Slope angle in degrees. 

* `slant` Slant angle in degrees. 

* `_fpgram` Output features parallelogram coordinates. 

* `randomize` Whether to do a random perturbation of extraction parameters. 

#### Returns
Features matrix.

#### `public bool `[`isImageFormat`](#class_text_feat_extractor_1abb7da8622bf364ef6bf5513779497d04)`()` 

Whether the configured output format is image.

#### `public void `[`write`](#class_text_feat_extractor_1aed77454431dd4d5e5c6d666e5cc10bfa)`(const cv::Mat & feats,FILE * file)` 

Prints features to a file stream using the configured output format.

#### Parameters
* `feats` OpenCV matrix containing the features. 

* `file` File stream to write the features.

#### `public void `[`write`](#class_text_feat_extractor_1ad59b31da84822d8f3ca24e80e778b7da)`(const cv::Mat & feats,const char * fname)` 

Writes features to a file using the configured output format.

#### Parameters
* `feats` OpenCV matrix containing the features. 

* `fname` File name of where to write the features.

# struct `iF1` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` `[`idx`](#structi_f1_1a856738e8766449fe26d0042c61be9afe) | 
`public `[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` `[`val`](#structi_f1_1aa9a659909748e7cd0c5f612b521180dd) | 

## Members

#### `public `[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` `[`idx`](#structi_f1_1a856738e8766449fe26d0042c61be9afe) 

#### `public `[`F1`](#mem_8h_1a65f193e3051f78e9c819cc0d597e19df)` `[`val`](#structi_f1_1aa9a659909748e7cd0c5f612b521180dd) 

# struct `iI1` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` `[`idx`](#structi_i1_1a3933dafa5a6b20181742416cbced8ad1) | 
`public `[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` `[`val`](#structi_i1_1ae231892ccf1661192b8acce4b656f128) | 

## Members

#### `public `[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` `[`idx`](#structi_i1_1a3933dafa5a6b20181742416cbced8ad1) 

#### `public `[`I1`](#mem_8h_1a86a866c8142917799f3c2ee021bff2d8)` `[`val`](#structi_i1_1ae231892ccf1661192b8acce4b656f128) 

# struct `IV2` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public int `[`x`](#struct_i_v2_1a8a4c24e1f19abf99afc565588a2756f2) | 
`public int `[`y`](#struct_i_v2_1a989614fa593b305982cfca15e02d48d1) | 

## Members

#### `public int `[`x`](#struct_i_v2_1a8a4c24e1f19abf99afc565588a2756f2) 

#### `public int `[`y`](#struct_i_v2_1a989614fa593b305982cfca15e02d48d1) 

# struct `NamedImage` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public std::string `[`id`](#struct_named_image_1a15cce4fef87364e870d24ce7af8bba7a) | 
`public std::string `[`name`](#struct_named_image_1a3091d87d082c33c731f47df06f7ffec3) | 
`public float `[`rotation`](#struct_named_image_1ab277b090578b630cbf481373def2e910) | 
`public int `[`direction`](#struct_named_image_1a014632405141de28d9ef5c3d8b33fd27) | 
`public int `[`x`](#struct_named_image_1a0ca2bf51b4d9e41ffc6013b6ebb0eb5f) | 
`public int `[`y`](#struct_named_image_1ae37031be3a775dc1bdab07378169bc61) | 
`public `[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` `[`image`](#struct_named_image_1ad3acaf8a72f72434ff9474dfeee81a03) | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`node`](#struct_named_image_1a0ea94db18d30fd437a8424cf742afb9d) | 
`public inline  `[`NamedImage`](#struct_named_image_1a70560cf030f1554b2ebe91e01584d30f)`()` | 
`public inline  `[`NamedImage`](#struct_named_image_1af33a1269609e69b72d9b1e3425e09309)`(std::string _id,std::string _name,double _rotation,int _direction,int _x,int _y,`[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` _image,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` _node)` | 

## Members

#### `public std::string `[`id`](#struct_named_image_1a15cce4fef87364e870d24ce7af8bba7a) 

#### `public std::string `[`name`](#struct_named_image_1a3091d87d082c33c731f47df06f7ffec3) 

#### `public float `[`rotation`](#struct_named_image_1ab277b090578b630cbf481373def2e910) 

#### `public int `[`direction`](#struct_named_image_1a014632405141de28d9ef5c3d8b33fd27) 

#### `public int `[`x`](#struct_named_image_1a0ca2bf51b4d9e41ffc6013b6ebb0eb5f) 

#### `public int `[`y`](#struct_named_image_1ae37031be3a775dc1bdab07378169bc61) 

#### `public `[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` `[`image`](#struct_named_image_1ad3acaf8a72f72434ff9474dfeee81a03) 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`node`](#struct_named_image_1a0ea94db18d30fd437a8424cf742afb9d) 

#### `public inline  `[`NamedImage`](#struct_named_image_1a70560cf030f1554b2ebe91e01584d30f)`()` 

#### `public inline  `[`NamedImage`](#struct_named_image_1af33a1269609e69b72d9b1e3425e09309)`(std::string _id,std::string _name,double _rotation,int _direction,int _x,int _y,`[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` _image,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` _node)` 

# struct `rgb` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public unsigned char `[`r`](#structrgb_1a2e51db126cff93863d52bb429fbc422d) | 
`public unsigned char `[`g`](#structrgb_1aaa90468fc445cd4003cea65a84dea3e8) | 
`public unsigned char `[`b`](#structrgb_1ae99e63aa161acf8066058b7af8b3e02c) | 

## Members

#### `public unsigned char `[`r`](#structrgb_1a2e51db126cff93863d52bb429fbc422d) 

#### `public unsigned char `[`g`](#structrgb_1aaa90468fc445cd4003cea65a84dea3e8) 

#### `public unsigned char `[`b`](#structrgb_1ae99e63aa161acf8066058b7af8b3e02c) 

Generated by [Moxygen](https://sourcey.com/moxygen)