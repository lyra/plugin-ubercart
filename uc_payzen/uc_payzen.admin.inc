<?php
/**
 * Copyright © Lyra Network.
 * This file is part of PayZen for Ubercart. See COPYING.md for license details.
 *
 * @author    Lyra Network <https://www.lyra.com>
 * @copyright Lyra Network
 * @license   http://www.gnu.org/licenses/old-licenses/gpl-2.0.html GNU General Public License (GPL v2)
 */

function theme_uc_payzen_backend_multi_options($variables)
{
    drupal_add_js(drupal_get_path('module', 'uc_payzen') . '/uc_payzen.admin.js');
    drupal_add_css(drupal_get_path('module', 'uc_payzen') . '/uc_payzen.admin.css');

    $multi_options = uc_payzen_multi_options();

    $output = '';

    $output .= '<div>';
    $output .= '<button id="uc_payzen_multi_options_btn"' . (!empty($multi_options) ? ' style="display: none;"' : '')
                    . ' type="button"  onclick= "payzenAddOption(true, \'' . uc_payzen_t('Delete') . '\')" />' . uc_payzen_t('Add') . '</button>';

    $output .= '<table id="uc_payzen_multi_options_table"' . (empty($multi_options) ? ' style="display: none;"' : '') . ' cellpadding="0" cellspacing="0" class="uc-payzen-table" >
                    <thead>
                        <tr>
                            <th>' . uc_payzen_t('Label') . '</th>
                            <th>' . uc_payzen_t('Min. amount') . '</th>
                            <th>' . uc_payzen_t('Max. amount') . '</th>
                            <th>' . uc_payzen_t('Contract') . '</th>
                            <th>' . uc_payzen_t('Count') . '</th>
                            <th>' . uc_payzen_t('Period') . '</th>
                            <th>' . uc_payzen_t('1st payment') . '</th>
                            <th></th>
                        </tr>
                    </thead>
                    <tbody>';


    if (!empty($multi_options)) {
        foreach ($multi_options as $key => $option) {
            $output .= '<tr id="uc_payzen_multi_option_' . $key . '">
                            <td>' . uc_payzen_create_text('uc_payzen_multi_options[' . $key . '][label]', $option['label'], 'style="width: 150px;"') . '</td>
                            <td>' . uc_payzen_create_text('uc_payzen_multi_options[' . $key . '][amount_min]', $option['amount_min'], 'style="width: 80px;"') . '</td>
                            <td>' . uc_payzen_create_text('uc_payzen_multi_options[' . $key . '][amount_max]', $option['amount_max'], 'style="width: 80px;"') . '</td>
                            <td>' . uc_payzen_create_text('uc_payzen_multi_options[' . $key . '][contract]', $option['contract'], 'style="width: 70px;"') . '</td>
                            <td>' . uc_payzen_create_text('uc_payzen_multi_options[' . $key . '][count]', $option['count'], 'style="width: 70px;"') . '</td>
                            <td>' . uc_payzen_create_text('uc_payzen_multi_options[' . $key . '][period]', $option['period'], 'style="width: 70px;"') . '</td>
                            <td>' . uc_payzen_create_text('uc_payzen_multi_options[' . $key . '][first]', $option['first'], 'style="width: 70px;"') . '</td>
                            <td> <button type="button" onclick="payzenDeleteOption(' . $key . ');">' . uc_payzen_t('Delete') . '</button> </td>
                        </tr>';
        }
    }

    $output .= '        <tr id="uc_payzen_multi_option_add">
                            <td colspan="7"></td>
                            <td><button type="button" onclick="payzenAddOption(false, \'' . uc_payzen_t('Delete') . '\');" >' . uc_payzen_t('Add') . '</button></td>
                        </tr>
                    </tbody>
                </table>
            </div>';

    return $output;
}

function uc_payzen_create_text($name, $value, $extra_attributes = '')
{
    $output = '<input type="text" name="' . $name . '" value="' . $value . '" ' . $extra_attributes . '>';
    return $output;
}
