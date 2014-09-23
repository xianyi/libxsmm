#include <immintrin.h>
#include <stdio.h>

#ifdef __MIC__

__declspec( target (mic))
inline __m512d   _MM512_LOADU_PD(const double* a) {
  __m512d va= _mm512_setzero_pd();
  va=_mm512_loadunpacklo_pd(va, &a[0]);
  va=_mm512_loadunpackhi_pd(va, &a[8]);
  return va;
}

__declspec( target (mic))
inline void _MM512_STOREU_PD(double* a, __m512d v) {
  _mm512_packstorelo_pd(&a[0], v);
  _mm512_packstorehi_pd(&a[8], v);
}

__declspec( target (mic))
inline __m512d _MM512_MASK_LOADU_PD(const double* a, char mask) {
  __m512d va= _mm512_setzero_pd();
  va=_mm512_mask_loadunpacklo_pd(va, mask,&a[0]);
  va=_mm512_mask_loadunpackhi_pd(va, mask,&a[8]);
  return va;
}

__declspec( target (mic))
inline void _MM512_MASK_STOREU_PD(double* a, __m512d v, char mask) {
  _mm512_mask_packstorelo_pd(&a[0], mask, v);
  _mm512_mask_packstorehi_pd(&a[8], mask, v);
}

/*
__declspec( target (mic))
void print512d(__m512d a){
  double* f = (double *) _mm_malloc(sizeof(double)*8,64);
  _mm512_store_pd(f,a);
  printf("%f %f %f %f %f %f %f %f\n",f[0],f[1],f[2],f[3],f[4],f[5],f[6],f[7]);
  _mm_free(f);
}
*/

#endif