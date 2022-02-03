#Best depth 8
if (((ECG_HR_min_div_harmmean<(-0.25-IT_LF_min))and(0<(-0.25+HAND_EDA_processed_prctile25)))or(((0.25*0)**-1)>(IT_BRV_std**0.5)))and((((0.25+HAND_EDA_Original_mad)<ECG_p_MF_mad)and((ECG_hrv_harmmean-1)<0))or(((ECG_HR_min_div_max/HAND_EDA_Functionals_power_Originalmin)<-0.75)and(0<ECG_hrv_median))):
    if  ((1<IT_Original_baseline)or (0>(HAND_EDA_processed_baseline+-0.25))) or ((0.25<ECG_HR_min_div_prctile25) and (0.75<ECG_original_min) and (0 < HAND_EDA_Filt2_max)):
        if (0.5 - ECG_EI < -1) or (IT_BRV_harmmean > IT_BRV_std):
            if -0.75 > ECG_HR_min_div_harmmean:
                emotional
            else:
                if ARM_EDA_Functionals_power_Filt2prctile75 > 0.25:
                    mental
                else:
                    emotional
        else:
            neutral
    else:
        if (ECG_p_MF_trimmean25 < ECG_RR_window_prctile75) or (IT_MF_std > ECG_DBD - 0.5):
            emotional
        else:
            physical
else:
    if (0.5 < ECG_hrv_median or 0 < IT_LF_median) and (-0.75 < IT_LF_median) and (IT_Original_baseline > 0):
        if (IT_LF_trimmean25 > HAND_EDA_Functionals_power_Originalmin**0.25) and 0.25 < ECG_hrv_median:
            emotional
        else:
            physical
    else:
        if IT_BRV_std < IT_BRV_std or IT_MF_kurtosis < -0.25:
            neutral
        else:
            if ECG_hrv_median < -0.75 - ARM_EDA_Functionals_power_Fil12baseline:
                emotional
            else:
                mental


#Best depth 5
if IT_RF_mean >= 0.25 or ECG_hrv_median >= IT_BRV_std:
    if IT_MF_trimmean25<=IT_Original_mad:
        physical
    else:
        mental
else:
    if IT_MF_HF >= IT_VLF_baseline:
        emotional
    else:
        neutral

#Best depth 7
if 0.0625 > IT_PSD_kurtosis:
    if 1 >= IT_PSD_kurtosis:
        if ARM_EDA_Filt2_harmmean < IT_PSD_median and -1!=-0.25:
            neutral
        else:
            emotional
    else:
        physical
else:
    if ECG_hrv_prctile25 > 0.35 * ECG_p_MF_min:
        if IT_MF_skewness >= -0.5:
            if IT_PSD_baseline > 0:
                mental
            else:
                physical
        else:
            if -0.25 > IT_RF_Area:
                emotional
            else:
                emotional
    else:
        if (-0.5 - IT_Original_trimmean25) < IT_BRV_harmmean:
            if ECG_amplitude_RR_prctile25 > HAND_EDA_processed_min:
                mental
            else:
                emotional
        else:
            if ARM_EDA_Filt1_mad > IT_Original_prctile25:
                neutral
            else:
                mental