/******************************************************************************
** Copyright (c) 2014-2015, Intel Corporation                                **
** All rights reserved.                                                      **
**                                                                           **
** Redistribution and use in source and binary forms, with or without        **
** modification, are permitted provided that the following conditions        **
** are met:                                                                  **
** 1. Redistributions of source code must retain the above copyright         **
**    notice, this list of conditions and the following disclaimer.          **
** 2. Redistributions in binary form must reproduce the above copyright      **
**    notice, this list of conditions and the following disclaimer in the    **
**    documentation and/or other materials provided with the distribution.   **
** 3. Neither the name of the copyright holder nor the names of its          **
**    contributors may be used to endorse or promote products derived        **
**    from this software without specific prior written permission.          **
**                                                                           **
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS       **
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT         **
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR     **
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT      **
** HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,    **
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  **
** TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR    **
** PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    **
** LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING      **
** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS        **
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.              **
******************************************************************************/
/* Alexander Heinecke (Intel Corp.)
******************************************************************************/

#ifndef GENERATOR_DENSE_COMMON_H
#define GENERATOR_DENSE_COMMON_H

void libxsmm_generator_dense_add_isa_check_header( char**       io_generated_code, 
                                                   const char*  i_arch );

void libxsmm_generator_dense_add_isa_check_footer( char**       io_generated_code, 
                                                   const char*  i_arch );

void libxsmm_generator_dense_add_flop_counter( char**             io_generated_code, 
                                               const unsigned int i_m,
                                               const unsigned int i_n,
                                               const unsigned int i_k );

void libxsmm_generator_dense_sse_avx_open_kernel( char**             io_generated_code,
                                                  const unsigned int i_gp_reg_a,
                                                  const unsigned int i_gp_reg_b,
                                                  const unsigned int i_gp_reg_c,
                                                  const unsigned int i_gp_reg_pre_a,
                                                  const unsigned int i_gp_reg_pre_b,
                                                  const unsigned int i_gp_reg_mloop,
                                                  const unsigned int i_gp_reg_nloop,
                                                  const unsigned int i_gp_reg_kloop,
                                                  const char* i_prefetch);

void libxsmm_generator_dense_sse_avx_close_kernel( char**      io_generated_code,
                                                   const unsigned int i_gp_reg_a,
                                                   const unsigned int i_gp_reg_b,
                                                   const unsigned int i_gp_reg_c,
                                                   const unsigned int i_gp_reg_pre_a,
                                                   const unsigned int i_gp_reg_pre_b,
                                                   const unsigned int i_gp_reg_mloop,
                                                   const unsigned int i_gp_reg_nloop,
                                                   const unsigned int i_gp_reg_kloop,
                                                   const char* i_prefetch);

void libxsmm_generator_dense_header_kloop(char**             io_generated_code,
                                          const unsigned int i_gp_reg_kloop,
                                          const unsigned int i_m_blocking,
                                          const unsigned int i_k_blocking);

void libxsmm_generator_dense_footer_kloop(char**             io_generated_code,
                                          const unsigned int i_gp_reg_kloop,
                                          const unsigned int i_gp_reg_b,
                                          const unsigned int i_m_blocking,
                                          const unsigned int i_k,
                                          const unsigned int i_datatype_size,
                                          const unsigned int i_kloop_complete );

void libxsmm_generator_dense_header_nloop(char**             io_generated_code,
                                          const unsigned int i_gp_reg_mloop,
                                          const unsigned int i_gp_reg_nloop,
                                          const unsigned int i_n_blocking);

void libxsmm_generator_dense_footer_nloop(char**             io_generated_code,
                                          const unsigned int i_gp_reg_a,
                                          const unsigned int i_gp_reg_b,
                                          const unsigned int i_gp_reg_c,
                                          const unsigned int i_gp_reg_nloop,
                                          const unsigned int i_n_blocking,
                                          const unsigned int i_m,
                                          const unsigned int i_n,
                                          const unsigned int i_ldb,
                                          const unsigned int i_ldc,
                                          const char*        i_prefetch,
                                          const unsigned int i_gp_reg_pre_b,
                                          const unsigned int i_datatype_size);

void libxsmm_generator_dense_header_mloop(char**             io_generated_code,
                                          const unsigned int i_gp_reg_mloop,
                                          const unsigned int i_m_blocking );

void libxsmm_generator_dense_footer_mloop(char**             io_generated_code,
                                          const unsigned int i_gp_reg_a,
                                          const unsigned int i_gp_reg_c,
                                          const unsigned int i_gp_reg_mloop,
                                          const unsigned int i_m_blocking,
                                          const unsigned int i_m,
                                          const unsigned int i_k,
                                          const unsigned int i_lda,
                                          const char*        i_prefetch,
                                          const unsigned int i_gp_reg_pre_b,
                                          const unsigned int i_datatype_size);

#endif /* GENERATOR_DENSE_COMMON_H */